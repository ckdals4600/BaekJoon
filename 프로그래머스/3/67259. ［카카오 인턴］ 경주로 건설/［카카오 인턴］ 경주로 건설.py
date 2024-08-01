# from heapq import heappush, heappop

# def solution(board):
#     answer = 0
#     n = len(board)
#     table = [[[-1,-1] for _ in range(n) ] for _ in range(n)] #cost, 방향(상하 0 좌우 1 상하좌우 2)
#     table[0][0] = [0,2]
    
#     def dp(x,y):
#         if table[y][x] != [-1,-1]:
#             return table[y][x]
        
#         directions = [(1,0,1),(-1,0,1),(0,1,0),(0,-1,0)] 
        
#         res = [float("inf"),-1]
#         for dx,dy,d in directions:
#             mx,my = x+dx, y+dy
            
#             if not (0 <= mx < n and 0 <= my < n):
#                 continue
            
#             cost, status = dp(mx,my)
            
#             cost = cost + 100 if status == 2 or status == d else cost + 500
#             if cost < res[0]:
#                 res = [cost, d]
            
#         table[y][x] = res
#         return res
    
#     dp(n-1,n-1)
#     return answer

# from heapq import heappush, heappop
# import math

# def solution(board):
#     for b in board:
#         print(b)
#     answer = 0
#     n = len(board)
    
#     table = [[math.inf] * n for _ in range(n)]
    
#     q = []
#     heappush(q,[0,0,0,2]) #cost,x,y,방향(상하 0 좌우 1)
#     table[0][0] = 0
    
#     while q:
#         cost,x,y,direct = heappop(q)
#         print(cost,x,y,direct)
#         if table[y][x] < cost:
#             continue
        
#         if x == n-1 and y == n-1:
#             table[y][x] = min(table[y][x], cost)
        
#         directions = [(0,1,0),(0,-1,0),(1,0,1),(-1,0,1)] 
        
#         for dx,dy,d in directions:
#             mx,my = x+dx, y+dy
#             mcost = cost + 100 
#             if direct != 2 and direct != d:
#                 mcost += 500
            
#             if not (0 <= mx < n and 0 <= my < n) or board[my][mx] == 1:
#                 continue
            
#             if table[my][mx] >= mcost:
#                 table[my][mx] = min(mcost, table[my][mx])
#                 heappush(q,[mcost,mx,my,d])
    

#     return table[n-1][n-1]

from collections import deque
import math

def solution(board):
    answer = 0
    n = len(board)
    
    table = [[math.inf] * n for _ in range(n)]
    
    q = deque()
    q.append([0,0,0,2]) #cost,x,y,방향(상하 0 좌우 1)
    table[0][0] = 0
    
    while q:
        cost,x,y,direct = q.popleft()
        
        if table[y][x] + 500 < cost:
            continue
                
        if x == n-1 and y == n-1:
            table[y][x] = min(table[y][x], cost)
            continue
            
        directions = [(0,-1,0),(0,1,0),(1,0,1),(-1,0,1)] 
        
        for dx,dy,d in directions:
            mx,my = x+dx, y+dy
            mcost = cost + 100 
            if direct != 2 and direct != d:
                mcost += 500
            
            if not (0 <= mx < n and 0 <= my < n) or board[my][mx] == 1:
                continue
            
            if table[my][mx] > mcost:
                table[my][mx] = mcost
                q.append([mcost,mx,my,d])
            elif table[my][mx] + 500 > mcost:
                q.append([mcost,mx,my,d])
            

    return table[n-1][n-1]