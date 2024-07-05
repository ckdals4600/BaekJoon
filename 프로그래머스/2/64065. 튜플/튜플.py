def solution(s):
    answer = []
    s = s[2:-2]
    s = [set(map(int,s.split(","))) for s in s.split("},{")]
    s.sort(key=len)
    
    tuples = list(s[0])
    
    for i in range(1,len(s)):
        tuples.append(list(s[i] - s[i-1])[0])
    
    answer = tuples
    
    return answer