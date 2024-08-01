def solution(cap, n, deliveries, pickups):
    answer = 0    
    
    d = -1
    p = -1
    
    for i in range(n-1,-1,-1):
        
        if d == -1 and deliveries[i]:
            d = i
        if p == -1 and pickups[i]:
            p = i
            
        if d != -1 and p != -1:
            break

    while d > -1 or p > -1:
        answer += max(d+1,p+1)*2
        
        d_sum = 0
        for i in range(d,-1,-1):
            d_sum += deliveries[i]
            deliveries[i] = 0

            if d_sum > cap:
                deliveries[i] = d_sum-cap
                d = i
                break
                
        if d_sum <= cap:
            d = -1
                
        p_sum = 0
        for i in range(p,-1,-1):
            p_sum += pickups[i]
            pickups[i] = 0

            if p_sum > cap:
                pickups[i] = p_sum-cap
                p = i
                break
                
        if p_sum <= cap:
            p = -1
                
        
    
    return answer