from itertools import permutations
import math

n,m,k = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
all_infos = list(permutations([list(map(int, input().split())) for _ in range(k)],k))

def rotate(info, a):
    r,c,s = info
    r,c = r-1, c-1

    
    for i in range(s):
        top, bottom, left, right = r-s+i, r+s-i, c-s+i, c+s-i
        last = a[top][left]
        

        for j in range(left+1,right):
            a[top][j], last = last, a[top][j]
        for j in range(top,bottom):
            a[j][right], last = last, a[j][right]
        for j in range(right, left, -1):
            a[bottom][j], last = last, a[bottom][j]
        for j in range(bottom, top-1, -1):
            a[j][left], last = last, a[j][left]

    return a

def rotate_all(infos, a):
    for info in infos:
        rotate(info,a)
    res = math.inf
    for l in a:
        res = min(sum(l),res)
    
    return res

res = math.inf
for infos in all_infos:
    b = [arr[:] for arr in a]
    res = min(res, rotate_all(infos, b))

print(res)