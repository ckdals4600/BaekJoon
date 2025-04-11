def solution(n, wires):
    answer = 100
    
    tree = [[] for _ in range(n)]
    sub = [1]*n #[[1] for i in range(n)]
    
    for s,d in wires:
        s,d = s-1,d-1
        
        tree[s].append(d)
        tree[d].append(s)

    def findSub(p, c):
        sum = 0
        
        for node in tree[c]:
            if node != p:
                sub[c] += findSub(c,node)
        
        return sub[c]
        
    findSub(-1,0)
    
    for i in sub:
        c = abs(i-(n-i))
        if answer > c:
            answer = c
    
    return answer