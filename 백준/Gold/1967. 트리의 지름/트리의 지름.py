import sys
from collections import deque

input = sys.stdin.readline
sys.setrecursionlimit(10**4)

nodeNum = int(input())
tree = [[] for _ in range(nodeNum) ]

for i in range(nodeNum-1):
    parent, child, weight = map(int, input().split())
    parent, child = parent-1, child -1

    tree[parent].append([child,weight])
    tree[child].append([parent,weight])   


def dfs(start):
    maxNode = start
    dq = deque()

    visit = set()
    dq.append([start, 0])
    maxWeight = 0

    while dq:
        nodeInfo = dq.pop()
        node,height = nodeInfo[0],nodeInfo[1]
        visit.add(node)
        for tempNode,tempHeight in tree[node]:
            if(tempNode in visit):
                continue
            
            tempHeight += height

            if(tempHeight > maxWeight):
                maxWeight = tempHeight
                maxNode = tempNode
            dq.append([tempNode, tempHeight])
    
    return maxNode, maxWeight

print(dfs(dfs(0)[0])[1])