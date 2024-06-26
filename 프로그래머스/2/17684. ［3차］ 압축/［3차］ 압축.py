# 입력 길이 1000글자 -> O(n^2) 괜찮다고 생각

# 1
# 구현 문제, 딕셔너리 활용
def solution(msg):
    answer = []
    dic = {}
    
    for i in range(ord('A'),ord('Z') + 1):
        dic[chr(i)] = i - ord('A') + 1
    

    while msg:
        i = 1
        while True :
            w = msg[:i]
            
            if i > len(msg):
                answer.append(dic[msg])
                msg = ''
                break
            
            
            if msg[:i+1] not in dic:
                answer.append(dic[w])
                
                c = msg[i:i+1]
                dic[w + c] = len(dic.keys()) + 1
                
                msg = msg[i:]
                break
            else:
                i += 1
    
    print(dic)
    return answer