import math

def solution(n, k):
    
    def chageToK(n,k):
        res = 0
        maxLen = k
        while(n > maxLen*k):
            maxLen *= k
        
        while(maxLen > 0):
            res = res * 10 + n//maxLen
            n -= maxLen * (n//maxLen)
            maxLen //= k
            
        return res
    
    def chkPrime(n):
        if n == 1:
            return False
        
        for i in range(2,int(math.sqrt(n)+1)):
            if n % i == 0:
                return False
        return True
    
    answer = 0
    kNum = chageToK(n, k)
    num = 0
    mul = 1
    
    while(kNum > 0 or num != 0):
        if kNum%10 == 0:   
            answer = answer + 1 if num > 1 and chkPrime(num) else answer
            num = 0
            mul = 1
            kNum //= 10
            continue
            
        num += (kNum%10) * mul
        mul *= 10
        kNum //= 10
        
        
    
    return answer