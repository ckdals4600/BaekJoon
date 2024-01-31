from collections import deque

c_num = int(input())
l_num = int(input())
d = {i+1 : [] for i in range(c_num)}

for i in range(l_num):
    j,k = map(int, input().split())
    d[j].append(k)
    d[k].append(j)

visit = set()
visit.add(1)
q = deque()
q.appendleft(1)

while q:
    for i in d.get(q.popleft(),[]) :
        if i not in visit:
            q.appendleft(i)
            visit.add(i)
        
print(len(visit) - 1)