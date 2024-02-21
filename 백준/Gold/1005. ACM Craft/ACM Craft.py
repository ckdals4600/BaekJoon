import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

T = int(input())

result = []
for _ in range(T):
    buildingN, ruleN = map(int, input().split())
    times = list(map(int, input().split()))
    rules = {i+1 : [] for i in range(buildingN)}
    
    for _ in range(ruleN):
        first, second = map(int, input().split())
        rules[second].append(first)

    w = int(input())
    timeMap = [-1] * buildingN

    def findTime(b):
        b -= 1
        if timeMap[b] != -1:
            return timeMap[b]
        
        timeMap[b] = times[b]
        m = 0
        for i in rules[b+1]:
            m = max(m, findTime(i)) 
        timeMap[b] += m
        return timeMap[b]
    
    print(findTime(w))