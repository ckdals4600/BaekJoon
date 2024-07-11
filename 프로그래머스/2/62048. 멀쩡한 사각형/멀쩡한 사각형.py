import math

def solution(w,h):
    
    count = 0
    w,h = min(w,h), max(w,h)
    
    
    gcd = math.gcd(w,h)
    sx = w//gcd
    
    y = 1
    for i in range(1,sx + 1):
        new_y = math.ceil(h * i / w) 
        count += (new_y - y) + 1
        if int(h * i / w) == new_y:
            new_y += 1
        y = new_y
        
    count *= w//sx
    
    answer = w*h - count
    return answer
