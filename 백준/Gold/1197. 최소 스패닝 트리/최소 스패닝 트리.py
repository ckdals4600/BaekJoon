from queue import PriorityQueue

v_num, e_num = map(int, input().split())

q = PriorityQueue()
p = [i for i in range(v_num)]
tree_cost = 0

def find(x):
    if p[x] != x:
        return find(p[x])
    return x

def merge(a,b):
    if a > b:
        p[a] = b
    else:
        p[b] = a

for _ in range(e_num):
    q.put(list(map(int,input().split()))[::-1])


while not q.empty():
    n = q.get()
    e, v1, v2 = n[0], n[1], n[2]
    v1 = find(v1 - 1)
    v2 = find(v2 - 1)

    if v1 != v2:
        tree_cost += e
        merge(v1,v2)

print(tree_cost)