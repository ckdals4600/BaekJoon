import itertools

def solution(cards):
    answer = 0
    
    groups = []
    
    def find_group(num):
        for group in groups:
            if num in group:
                return
            
        group = set()
        start = num
        
        while start not in group:
            group.add(start)
            start = cards[start-1]
        
        groups.append(group)
    
    n = len(cards)
    for i in range(1,n + 1):
        find_group(i)
    
    len_group = [len(group) for group in groups]
    len_group = itertools.combinations(len_group,2)
    
    for i,j in len_group:
        answer = max(answer, i*j)
    
        
        
    return answer