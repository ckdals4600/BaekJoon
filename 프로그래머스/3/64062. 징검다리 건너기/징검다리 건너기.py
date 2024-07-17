# def solution(stones, k):
#     answer = 0
    
#     sums = [0] + stones[:]
    
#     for i in range(1,len(sums)):
#         sums[i] += sums[i-1]
    
#     while True:
#         i = 0
        
#         while i < len(sums):
#             print(sums)
#             start = i if i != 0 else 1
#             end = i + k if i + k < len(sums) else len(sums) - 1
            
#             if sums[end] <= sums[i]:
#                 break
            
#             for j in range(start, end):
#                 sums[j] -= 1

#             i += k
            
#         if i < len(sums):
#             break
        
#         answer += 1
        
#     return answer

from collections import deque
import math

def solution(stones, k):
    answer = math.inf
    q = deque()
    
    if len(stones) == k:
        return max(stones)
        
    for i in range(len(stones)):
        
        
        while q and q[-1][0] < stones[i]:
                q.pop()
                
        while q and q[0][1] <= i - k:
                q.popleft()
                
        q.append([stones[i], i])
        if q and i >= k - 1:
            answer = min(answer, q[0][0])
    if answer == math.inf:
        return 0
    
    return answer