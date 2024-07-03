n = int(input())
loss = [0] + list(map(int, input().split()))
happy = [0] + list(map(int, input().split()))
table = [[0] * 101 for _ in range(n+1)]

for i in range(1,n+1):
    for j in range(1,101):
        if loss[i] <= j:
            table[i][j] = max(table[i-1][j], table[i-1][j-loss[i]] + happy[i])
        else:
            table[i][j] = table[i-1][j]

print(table[n][99])