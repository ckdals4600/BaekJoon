import sys
from heapq import heappop, heappush, heapify

input = sys.stdin.readline
sys.setrecursionlimit(10**4)

houseNum, roadNum = map(int, input().split())

road = [[] for _ in range(houseNum)]

for _ in range(roadNum):
    start, end, weight = map(int, input().split())
    start, end = start - 1, end - 1
    road[start].append((weight, end))
    road[end].append((weight, start))

visit=set()
totalWeight = 0
maxWeight = 0
heap = road[0]
heapify(heap)
visit.add(0)

while len(visit) < houseNum: 
    weight, node = heappop(heap)

    if(node in visit):
        continue

    visit.add(node)
    totalWeight += weight
    
    if(maxWeight < weight):
        maxWeight = weight

    for temp in road[node]:
        if(temp[1] in visit):
            continue
        heappush(heap, temp)



totalWeight -= maxWeight
print(totalWeight)