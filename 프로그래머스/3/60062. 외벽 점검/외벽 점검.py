#1
#그리드 및 백트래킹 해결 하려함 -> 코드가 너무 복잡해지고 어떻게 구현해야할지 막막해서 실패
# def solution(n, weak, dist):
#     answer = 9999999999
    
#     def addVisited(start, num, visited):
#         nxt = start + 1
#         loop = 0
#         while len(visited) < len(weak):
#             if nxt >= len(weak):
#                 nxt -= len(weak)
#                 loop += 1
            
#             if weak[nxt] > weak[start] + dist[num] - loop * n:
#                 break
#             visited.add(weak[nxt])
            
#             nxt += 1
#         return nxt
        
    
#     def back(start, num, visited):
#         ret = 1
#         visited.add(weak[start])
        
#         nxt = addVisited(start, num, visited)
#         print(visited, nxt)
            
#         # if len(visited) < len(weak) and num != 0:
#         #     min_len = 9999999999999999
#         #     for i in range(len(weak)-len(visited)):
#         #         nxt = nxt + 1 if nxt + 1 < len(weak) else nxt + 1 - len(weak)
#         #         min_len = min(back(nxt, num-1, visited), min_len)
    
#     for i in range(len(weak)):
#         back(i,-1,set())
    
#     return answer

#2
# permutation은 for문 할떄마다 생성해야하네 ?
import itertools

def solution(n, weak, dist):
    answer = -1
    
    def addVisited(start, num, visited):
        nxt = start
        loop = 0
        while len(visited) < len(weak):
            if nxt >= len(weak):
                nxt -= len(weak)
                loop += 1
            
            if weak[nxt] > weak[start] + num - loop * n:
                break
            visited.add(weak[nxt])
            
            nxt += 1
        return nxt
    
    
    for idx in range(len(weak)):
        for dists in itertools.permutations(dist):
            ptr = idx
            visited = set()
            min_candidate = 0
            
            for d in dists:
                ptr = addVisited(ptr, d, visited)
                min_candidate += 1
                
                if min_candidate > answer and answer != -1:
                    break

                if len(visited) == len(weak):
                    answer = min(answer, min_candidate) if answer != -1 else min_candidate
                    break

            
            
    
    return answer