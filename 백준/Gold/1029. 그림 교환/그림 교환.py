n = int(input())

sell = [list(map(int, input())) for _ in range(n)]
is_take = [[[0] * 10 for _ in range(n)] for _ in range(1 << n)]

def dp(takes, p, w):    
    if is_take[takes][p][w] != 0:
        return is_take[takes][p][w]

    ret = 0
    for i in range(1, n):
        if takes & (1 << i) or sell[p][i] < w:
            continue

        ret = max(ret, dp(takes | (1 << i), i, sell[p][i]) + 1)

    is_take[takes][p][w] = ret
    return ret

print(dp(1,0,0) + 1)