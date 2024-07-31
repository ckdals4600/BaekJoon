#1
#BFS -> 시작점에서부터 BFS 수행 -> 좌표, 걸린 시간, 레버 여부를 저장해서 레바 당긴 후 도착점에 도착할때까지 반복

# from collections import deque

# def solution(maps):
#     answer = -1
#     n,m = len(maps[0]), len(maps)
    
#     start= (0,0)
    
#     for y in range(m):
#         for x in range(n):
#             if maps[y][x] == "S":
#                 start = (x,y)
#                 break
    
    
#     que = deque()
#     que.append([x,y,0,False]) #현재 위치, 걸린 시간, 레버 여부
    
#     while que:
#         x,y,t,l = que.popleft()
        
#         directions = [(1,0),(-1,0),(0,1),(0,-1)]
        
#         for dx,dy in directions:
#             mx,my = x + dx, y + dy
            
#             if not ( 0 <= mx < n and 0 <= my < m):
#                 continue
            
#             if maps[my][mx] == "X":
#                 continue
            
#             if maps[my][mx] == "E" and l:
#                 answer = t+1
#                 break
                
#             que.append([mx,my, t+1, True if maps[my][mx] == "L" else l])
            
    
    
#     return answer

#2
# BFS 2번 수행 -> 시작점에서 레버, 레버에서 도착점

from collections import deque

def solution(maps):
    answer = -1
    n,m = len(maps[0]), len(maps)
    
    start = [0,0]
    lever = [0,0]
    
    for y in range(m):
        for x in range(n):
            if start != [0,0] and lever != [0,0]:
                break
                
            if maps[y][x] == "S":
                start = [x,y]
            elif maps[y][x] == "L":
                lever = [x,y]
                
    
    def bfs(x,y,end):
        vistied = [[0]*n for _ in range(m)]
        que = deque()
        que.append([x,y,0]) #현재 위치, 걸린 시간, 
        
        while que:
            x,y,t = que.popleft()

            directions = [(1,0),(-1,0),(0,1),(0,-1)]

            for dx,dy in directions:
                mx,my = x + dx, y + dy

                if not ( 0 <= mx < n and 0 <= my < m):
                    continue

                if maps[my][mx] == "X" or vistied[my][mx]:
                    continue

                if maps[my][mx] == end:
                    return t+1
                
                vistied[my][mx] = 1
                que.append([mx,my, t+1])
        
        return -1
    
    lever_bfs = bfs(start[0], start[1], "L")
    end_bfs = bfs(lever[0], lever[1], "E")
    
    answer = lever_bfs + end_bfs if lever_bfs != -1 and end_bfs != -1 else -1
    
    return answer