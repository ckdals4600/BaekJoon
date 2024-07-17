# 1
# dp로 풀이 -> 무한루프 발생

# from collections import defaultdict
# import math
# import sys

# sys.setrecursionlimit(10**6)

# def solution(board):
#     ly,lx = len(board),len(board[0])
#     answer = 0
    
#     table = [[-1] * lx for _ in range(ly)]
#     table[ly-1][lx-1] = 1
    
#     def promising(tx1,ty1,tx2,ty2):
#         if tx1 < 0 or ty1 < 0 or tx2 >= lx or ty2 >= ly:
#             return False
            
#         if board[ty1][tx1] == 1 or board[ty2][tx2] == 1:
#             return False
        
#         return True
                
#     def findroute(x1,y1,x2,y2):
#         print(x1,x2,y)
#         if table[y2][x2] != -1:
#             return table[y2][x2]
        
#         m_x = [1,-1,0,0]
#         m_y = [0,0,1,-1]
        
#         r = [1,-1,1,-1]
        
#         ret = math.inf
        
#         for i in range(4):
#             tx1 = x1 + m_x[i]
#             ty1 = y1 + m_y[i]
#             tx2 = x2 + m_x[i]
#             ty2 = y2 + m_x[i]
            
#             if not promising(tx1,ty1,tx2,ty2):
#                 continue
            
#             ret = min(ret, findroute(tx1,ty1,tx2,ty2) + 1)
            
#         for i in range(4):
#             if i < 2: 
#                 tx1 = x1
#                 ty1 = y1 
#                 tx2 = x1
#                 ty2 = y1 
#             else:
#                 tx1 = x2
#                 ty1 = y2 
#                 tx2 = x2
#                 ty2 = y2   
                
#             if y1 == y2:
#                 ty2 += r[i]
#             else:
#                 tx2 += r[i]
            
#             tx1, tx2 = min(tx1,tx2), max(tx1,tx2)
#             ty1, ty2 = min(ty1,ty2), max(ty1,ty2)
            
#             if not promising(tx1,ty1,tx2,ty2):
#                 continue
                
#             ret = min(ret, findroute(x1,y1,tx2,ty2) + 1)

            
#         table[y2][x2] = ret
        
#         return ret
    
#     print(findroute(0,0,1,0))
    
#     return answer

from heapq import heappush, heappop
import sys

sys.setrecursionlimit(10**6)

def solution(board):
    ly,lx = len(board),len(board[0])
    answer = 0
    
    table = [[[-1] * 2 for _ in range(lx)] for _ in range(ly)]
    q = []
    heappush(q, [0,0,0,0]) # time, xy, status(0 -> 가로 , 1 -> 세로)
    
    def promising(x,y):
        if x < 0 or y < 0 or x >= lx or y >= ly:
            return False
            
        if board[y][x] == 1:
            return False
        
        return True
    
    for i in board:
        print(i)
    
    while q:
        time,x1,y1,status = heappop(q)
        x2,y2 = x1,y1
        
        if status == 0:
            x2 += 1
        else:
            y2 += 1
        
        if x2 == lx - 1 and y2 == ly - 1:
            answer = time
            break
            
        if table[y1][x1][status] != -1:
            continue
            
        print(time, ":", x1,y1,x2,y2)
        table[y1][x1][status] = 1
        
        m_x = [1,-1,0,0]
        m_y = [0,0,1,-1]
        r = [1,-1,1,-1]
        
        for i in range(4):
            tx1 = x1 + m_x[i]
            ty1 = y1 + m_y[i]
            tx2 = x2 + m_x[i]
            ty2 = y2 + m_y[i]
            
            if not (promising(tx1,ty1) and promising(tx2,ty2)):
                continue
                
            heappush(q, [time+1,tx1,ty1,status])
            
        for i in range(4):
            if i < 2: 
                tx1 = x1
                ty1 = y1 
                tx2 = x1
                ty2 = y1 
                
                if status == 0 and not promising(x2, y2+ r[i]):
                    continue
                if status == 1 and not promising(x2+ r[i],y2):
                    continue
            else:
                tx1 = x2
                ty1 = y2 
                tx2 = x2
                ty2 = y2   
                
                if status == 0 and not promising(x1, y1+ r[i]):
                    continue
                if status == 1 and not promising(x1+ r[i], y1):
                    continue
            
            if status == 0:
                ty2 += r[i]
            else:
                tx2 += r[i]
            
            tx1, tx2 = min(tx1,tx2), max(tx1,tx2)
            ty1, ty2 = min(ty1,ty2), max(ty1,ty2)
            
            if not (promising(tx1,ty1) and promising(tx2,ty2)):
                continue

            if tx1 == tx2:
                heappush(q, [time+1,tx1,ty1,1])
            else:
                heappush(q, [time+1,tx1,ty1,0])
            
    
    return answer