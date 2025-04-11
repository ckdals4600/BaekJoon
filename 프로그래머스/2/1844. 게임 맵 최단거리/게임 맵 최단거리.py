from collections import deque

def solution(maps):
    que = deque()
    
    m = len(maps)
    n = len(maps[0])
    
    visit = [[-1]*n for _ in range(m)]
    visit[0][0] = 1
    
    que.append([0,0])
    
    direction = [(1,0),(-1,0),(0,1),(0,-1)]
    
    while que:
        x,y = que.popleft()
        
        for dx,dy in direction:
            mx = x + dx
            my = y + dy
            
            if not ( 0 <= mx < n and 0 <= my < m):
                continue
                
            if visit[my][mx] != -1 or maps[my][mx] == 0:
                continue
            
            visit[my][mx] = visit[y][x] + 1
            que.append([mx,my])

    
    return visit[m-1][n-1]