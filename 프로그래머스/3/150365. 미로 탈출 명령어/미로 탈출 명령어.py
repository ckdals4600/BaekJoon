# 1
# Best First Searcg
# from heapq import heappush, heappop

# def solution(n, m, x, y, r, c, k):
#     answer = 'impossible'
#     candidate = []
    
#     que = []
#     heappush(que ,["",y,x,0])
    
#     direction = [(0,-1,"u"),(1,0,"r"),(-1,0,"l"),(0,1,"d")]
    
#     while que:
#         route,x1,y1,t = heappop(que)
        
#         if t == k:
#             if (y1,x1) == (r,c):
#                 answer = route
#                 break
#             continue
        
#         for dx,dy,d in direction:
#             mx = x1 + dx
#             my = y1 + dy
#             mroute = route + d
#             mt = t + 1
            
#             if not (0 < mx <= m and 0 < my <= n):
#                 continue
            
#             heappush(que,[mroute, mx,my,mt,])
            
#     return answer

# 2

from collections import deque

def solution(n, m, x, y, r, c, k):
    answer = 'impossible'
    
    def distance(x,y):
        return abs(x-c) + abs(y-r)
    
    
    
    if distance(y,x) > k or (k - distance(y,x)) % 2:
        return answer
    
    que = deque()
    que.append(["",y,x,0])
    
    direction = [(0,-1,"u"),(1,0,"r"),(-1,0,"l"),(0,1,"d")]
    
    while que:
        route,x1,y1,t = que.pop()
        
        if (y1,x1) == (r,c):
            if t == k:
                answer = route
                break
            elif (k - t) % 2:
                break
        
        for dx,dy,d in direction:
            mx = x1 + dx
            my = y1 + dy
            mroute = route + d
            mt = t + 1
            
            if not (0 < mx <= m and 0 < my <= n):
                continue
            
            if distance(mx,my) + mt > k:
                continue
            
            que.append([mroute, mx,my,mt])
            
    return answer