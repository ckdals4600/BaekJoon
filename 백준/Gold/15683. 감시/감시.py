from collections import defaultdict

n,m = map(int, input().split())

v = [list(map(int, input().split())) for _ in range(n)]
cctvs = []

cctv_move = {
    1 : (((1,0,0,0),(0,0,0,0)), ((0,0,0,0),(0,0,1,0)), ((0,-1,0,0),(0,0,0,0)), ((0,0,0,0),(0,0,0,-1))),
    2 : (((1,-1,0,0),(0,0,0,0)), ((0,0,0,0), (0,0,1,-1))),
    3 : (((1,0,0,0),(0,0,1,0)), ((1,0,0,0),(0,0,0,-1)), ((0,-1,0,0),(0,0,0,-1)), ((0,-1,0,0),(0,0,1,0))),
    4 : (((1,-1,0,0),(0,0,1,0)), ((1,-1,0,0),(0,0,0,-1)), ((0,-1,0,0),(0,0,1,-1)), ((1,0,0,0),(0,0,1,-1))),
    5 : [[(1,-1,0,0),(0,0,1,-1)]]
             } #x,y,-x,-y

remain = 0

for y in range(n):
    for x in range(m):
        if v[y][x] == 0 :
            remain += 1
        elif v[y][x] != 6:
            cctvs.append([v[y][x], x, y])
        
cctvs = sorted(cctvs, key=lambda x:x[0])

def backtracking(v, remain):
    if not cctvs:
        return remain
    
    num, x, y = cctvs.pop()
    ret = remain
    
    for m_x,m_y in cctv_move[num]:
        tv = [arr[:] for arr in v]
        tremain = remain
        
        for i in range(4):
            if m_x[i] == 0 and m_y[i] == 0:
                continue
            
            tx = x
            ty = y
            
            while True:
               tx += m_x[i] 
               ty += m_y[i]
               
               if tx < 0 or ty < 0 or tx >= m or ty >= n:
                   break
               
               if tv[ty][tx] == 6:
                   break
               
               if tv[ty][tx] == 0:
                   tv[ty][tx] = -1
                   tremain -= 1
                   
        ret = min(backtracking(tv, tremain), ret)
    
    cctvs.append([num, x, y])
    
    return ret


print(backtracking(v, remain))