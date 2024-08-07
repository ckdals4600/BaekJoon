n,m = map(int,input().split())

memories = list(map(int, input().split()))
costs = list(map(int, input().split()))
max_costs = sum(costs)+1

table = [[0] * max_costs for _ in range(n + 1)]

answer = max_costs-1

for i in range(1,n+1):
    for j in range(max_costs):
        if j >= costs[i-1]:
            table[i][j] = max(table[i-1][j-costs[i-1]] + memories[i-1] ,table[i-1][j])
        else:
            table[i][j] = table[i-1][j]
            
        if table[i][j] >= m:
            answer = min(j, answer)
print(answer)