# 구현은 어렵지 않지만 해당 로직을 생각하는데 어렵
# 시간초과

from collections import deque

def solution(numbers):
    q = deque() #num
    answer = [-1] * len(numbers)
    
    for i in range(len(numbers)-1,-1,-1):
        n = numbers[i]
        
        while q and q[0] <= n:
            q.popleft()
        
        for num in q:
            if num > n:
                answer[i] = num
                break
                
        q.appendleft(n)
    

    return answer