import sys
import heapq
from collections import deque

input = sys.stdin.readline
print = sys.stdout.write

N, K = map(int, input().split())

gemList = deque()
bagList = [0] * K

for i in range(N):
    weight, cost = list(map(int, input().split()))
    gemList.append([weight, cost])

for i in range(K):
    bagList[i] = int(input())

bagList = sorted(bagList)
gemList = deque(sorted(gemList))

total = 0

tmpGem = []

for i in range(K):
    w = bagList[i]    

    while gemList:
        if w < gemList[0][0]:
            break
        heapq.heappush(tmpGem, -gemList.popleft()[1])

    if tmpGem:
        total -= heapq.heappop(tmpGem)


print(str(total))