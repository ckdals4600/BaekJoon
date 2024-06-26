import sys
sys.setrecursionlimit(10**6)

m,n = map(int, input().split())

v = [list(map(int, input().split())) for _ in range(m)]

dp = [[-1 for _ in range(n)] for _ in range(m)]

dp[0][0] = 1

def find_route(x,y):
    if dp[y][x] != -1:
        return dp[y][x]
    
    move_x = [0,0,1,-1]
    move_y = [1,-1,0,0]
    
    dp[y][x] = 0
    for i in range(4):
        cur_x = move_x[i] + x
        cur_y = move_y[i] + y
        
        if cur_x < 0 or cur_y < 0 or cur_x >= n or cur_y >= m:
            continue
        
        if v[y][x] < v[cur_y][cur_x]:
            dp[y][x] += find_route(cur_x,cur_y)
            
    return dp[y][x]

print(find_route(n-1, m-1))