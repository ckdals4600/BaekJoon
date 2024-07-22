# 힙 사용
# 양 수, 늑대 수, 현재 노드, 방문할 수 있는 노드에 대해 데이터를 넣음
# 시간 초과

# from collections import defaultdict
# from heapq import heappush, heappop

# def solution(info, edges):
#     answer = 0
    
#     tree = defaultdict(list)
    
#     for s,e in edges:
#         tree[s].append(e)      
    
#     h = []
    
#     heappush(h,[-1,0, 0, tree[0] ]) #양,늑대,node,next node
    
#     while h:
#         sheep,wolf,cur,nexts = heappop(h)
#         nexts += tree[cur]
        
#         if not nexts:
#             answer = max(answer, sheep)
#             break
        
#         for i in range(len(nexts)):
#             n = nexts[i]
#             t_sheep = sheep - 1 if info[n] == 0 else sheep
#             t_wolf = wolf + 1 if info[n] == 1 else wolf
            
#             if -t_sheep > t_wolf:
#                 heappush(h, [ t_sheep, t_wolf, n, nexts[:i] + nexts[i+1:] ])
    
#     return answer

# 비트마스크 상태공간? ㄷㄷㄷ

from heapq import heappush, heappop
from collections import defaultdict

def solution(info, edges):
    answer = 0
    
    n = len(info)
    tree = defaultdict(list)
    
    for s,e in edges:
        tree[s].append(e)    
    
    heap = []
    visited = set()
    
    heappush(heap, [-1,0,1]) #양, 늑대, 상태
    
    while heap:
        sheep, wolf, state = heappop(heap)
        
        if state in visited:
            continue
            
        answer = max(answer, -sheep)
        visited.add(state)
        
        for i in range(n):
            if state & (1 << i):
                
                for node in tree[i]:
                    
                    if not state & (1 << node) :
                        t_sheep = sheep - 1 if info[node] == 0 else sheep
                        t_wolf = wolf + 1 if info[node] == 1 else wolf

                        if -t_sheep > t_wolf:
                            heappush(heap, [t_sheep, t_wolf, state | (1 << node)])
    
    
    return answer