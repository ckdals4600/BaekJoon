"""
0 
1 
2 
1 0
1 1
1 2
2 0
2 1
2 2
1 0 0
1 0 1
"""

def solution(n, t, m, p):
    
    def convert(n,src):
        res = ""
        if src == 0:
            return "0"
        
        while src:
            num = src%n
            res = (str(num) if num < 10 else chr(ord('A') + (num - 10)) ) + res
            src = src // n
        
        return res
    
    answer = ''
    
    # n = 3
    # m = 5
    # p = 1
    # t = 6
    
    len_sum = 0
    i = 0
    num_len = n
    #print("i :",i,"len_sum : ",len_sum, "num_len :",num_len)
    while len(answer) < t:
        
        
        if len_sum < p <= len_sum + num_len*(i+1):
            num = (p - len_sum - 1) // (i+1) # 몇번째 숫자
            order = (p - len_sum - 1) % (i+1) # 몇번째 글자
            
            #print("p :" ,p , "num :", n**(i) + num if i > 0 else num, "order :", order)
            res = convert(n, n**(i) + num if i > 0 else num)
            
            #print("say :", res[order])
            answer += res[order]
            p += m
        else:
            len_sum += num_len * (i+1)
            i += 1
            num_len = n**(i+1) - n**(i)
            
            #print("i :",i,"len_sum : ",len_sum, "num_len :",num_len)
            
    print(answer)
    
    return answer