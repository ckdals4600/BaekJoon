# 모든 노드에서 완전 탐색 진행?
# 너무 시간이 오래 걸릴거 같다
# DP로 진행해보자
import sys

sys.setrecursionlimit(10**6)

n = int(input())
forest = [list(map(int, input().split())) for _ in range(n)]

table=[[-1]* n for _ in range(n)]

def find_route(x,y):
    if table[y][x] == -1:
        res = 0
        direction = ((1,0), (-1,0), (0,1), (0,-1))

        for dx, dy in direction:
            mx,my = x+dx, y+dy

            if 0 > mx or mx >= n or 0 > my or my >= n: 
                continue
            
            if forest[y][x] < forest[my][mx]:
                res = max(find_route(mx,my), res)
        
        table[y][x] = res + 1

    return table[y][x]

ans = 0
for y in range(n):
    for x in range(n):
        ans = max(find_route(x,y), ans)

print(ans)

# for t in table:
#     print(t)
