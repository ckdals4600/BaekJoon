def solution(n, words):
    answer = [0,0]
    duplicate = set([words[0]])
    
    i = 1
    while i < len(words):
        if words[i][0] != words[i-1][-1] or words[i] in duplicate:
            break
        
        duplicate.add(words[i])
        i += 1
    
    if i != len(words):
        answer = [i%n + 1, i//n + 1]

    return answer