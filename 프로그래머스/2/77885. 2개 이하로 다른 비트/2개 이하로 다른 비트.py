# 걍 모든 자리수 비교 -> 시간 초과

# def solution(numbers):
#     answer = []
    
#     def diff(bi1,bi2):
#         ans = len(bi2) - len(bi1)
#         bi2 = bi2[ans:]
        
#         for i in range(len(bi1)):
#             if bi1[i] != bi2[i]:
#                 ans += 1
        
#         return ans
        
    
#     def f(x):
#         bi1 = bin(x)[2:]
        
#         i = 0
#         while True:
#             i+=1
#             bi2 = bin(x+i)[2:]
            
#             if diff(bi1, bi2) <= 2:
#                 break
                
#         return x+i 
        
#     for i in numbers:
#         answer.append(f(i))
        
    
    
    
#     return answer


def solution(numbers):
    answer = []
    
    def f(x):
        bi1 = bin(x)[2:]
        num = 0
        
        for i in range(1,len(bi1)+1):
            if bi1[-i] == '0':
                break
            
            num += 1
        
        bi2 = list(bin(x+1))
        
        for i in range(1,num):
            bi2[-i] = '1'
            
        return int(''.join(bi2),2)
            
        
    for i in numbers:
        answer.append(f(i))
        
    
    
    
    return answer