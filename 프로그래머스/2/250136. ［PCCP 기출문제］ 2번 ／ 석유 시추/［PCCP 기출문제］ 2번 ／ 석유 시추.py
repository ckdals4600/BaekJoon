from collections import defaultdict, deque

def solution(land):
    answer = 0
    
    n,m = len(land[0]), len(land)
    land_dic = defaultdict(set)
    land_size = {}
    
    
    def find_land(sx,sy):
        land_num = 2 + len(land_size)
        size = 1
        q = deque()
        q.append([sx,sy])
        land[sy][sx] = land_num
        land_dic[sx].add(land_num)
        
        while q:
            x,y = q.pop()
            
            d = [(1,0),(-1,0),(0,1),(0,-1)]
            for dx,dy in d:
                mx, my = x+dx, y+dy
                
                if not (0 <= mx < n and 0 <= my < m):
                    continue

                if land[my][mx] == 1:
                    land[my][mx] = land_num
                    size += 1
                    q.append([mx,my])
                    land_dic[mx].add(land_num)
            
        land_size[land_num] = size
    
    for y in range(m):
        for x in range(n):
            if land[y][x] == 1:
                find_land(x,y)
    
    for ks, vs in land_dic.items():
        
        s = 0
        for v in vs:
            s += land_size[v]
        answer = max(answer, s)
                     
    return answer