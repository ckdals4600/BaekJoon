n = int(input())

route = [list(map(int, input().split())) for _ in range(n)]

table = [[-1] * n for _ in range(n)]

for i in range(n):
    table[i][n-1] = 0

def dp(start, order ):
    
    if table[start][order] == -1:
    
        for i,v in enumerate(route[start]):
            if v == 0:
                continue
            cost = dp(i, order+1)
            cost = cost + v if cost != -1 else -1
            if cost == -1:
                continue
            table[start][order] = min(cost , table[start][order]) if table[start][order] != -1 else cost
    return table[start][order]

ans = float('inf')
for i in range(n):
    num = dp(i,0)
    if num != -1:
        ans = min(num, ans) 
        
print(ans if ans != float('inf') else -1)