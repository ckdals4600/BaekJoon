n = int(input())
d = {}

for _ in range(n):
    b = input()
    d[b] = d.get(b,0) + 1

d = dict(sorted(d.items(),reverse=True))

print(sorted(d, key = lambda x:d[x]).pop())
