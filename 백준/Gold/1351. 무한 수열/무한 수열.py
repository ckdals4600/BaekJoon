n,p,q = map(int,input().split())

a = {}
a[0] = 1

def dp(i):
    if i in a:
        return a[i]
    
    a[i] = dp(i//p) + dp(i//q)
    return a[i]

print(dp(n))