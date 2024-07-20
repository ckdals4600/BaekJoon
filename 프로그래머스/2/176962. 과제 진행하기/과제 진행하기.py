from collections import deque

def solution(plans):
    answer = []
    
    def toMinute(time):
        h,m = map(int, time.split(":"))
        return h * 60 + m
    
    hw = deque()
    for name, start, time in plans:
        start = toMinute(start)
        hw.append([start,int(time),name])
        
    hw = deque(sorted(hw, key=lambda x:x[0]))
    
    wait = deque()
    
    while hw:
        s,t,n = hw.popleft()
        e = s + t
        if hw:
            w = hw[0][0] - e
        else:
            w = 100
        
        if w < 0:
            wait.append([-w,n])
        else:
            answer.append(n)
            if w > 0 and wait:
                tw,wn = wait.pop()
                hw.appendleft([e,tw,wn])
    
    print(hw)
    print(wait)
    
    
    return answer