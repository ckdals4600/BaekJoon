n = int(input())

w = []

for _ in range(n):
    temp = list(map(int, input().split()))
    d = {}
    for i in range(temp[0]):
        d[temp[i+1]] = d.get(temp[i+1],0) + 1
    
    v= list(d.values())
    m = max(v)
    if temp[0]//m < 2 and v.count(m) < 2:
        w.append(sorted(d,key=lambda x:d[x]).pop())
    else:
        w.append("SYJKGW")

for i in range(len(w)):
    print(w[i])