#dfs ?
#1
# 단순 dfs 풀이 -> 시간 초과
# import heapq
# from collections import defaultdict
    

# def solution(n, paths, gates, summits):
#     answer = []
#     path_d = defaultdict(dict)
    
#     for path in paths:
#         s,e,w = path
#         path_d[s][e] = w
#         path_d[e][s] = w
    
#     for i in path_d:
#         path_d[i] = dict(sorted(path_d[i].items(), key=lambda x:x[1]))
    

#     answer_temp = []
#     dq = []
#     for start in gates:
#         heapq.heappush(dq, [start, 0, [start]])
        
#         while dq:
#             node,intensity,path = heapq.heappop(dq)

#             for next_n,next_w in path_d[node].items():
#                 if next_n not in path and next_n not in gates:
                    
#                     if next_n in summits:
#                         answer_temp.append([next_n, next_w if intensity < next_w else intensity])
#                         break
                    
#                     heapq.heappush(dq, [next_n, next_w if intensity < next_w else intensity, path + [next_n]])
    
#     answer = min(answer_temp, key=lambda x: (x[1], x[0]))
    
#     return answer

# 2
# 다익스트라 이용
# 실패 이유 https://hz25.tistory.com/6

# import heapq
# from collections import defaultdict
    
# INF = int(1e9)
    
# def solution(n, paths, gates, summits):
#     answer = []
#     path_d = defaultdict(dict)
    
#     for s,e,w in paths:
#         path_d[s][e] = w
#         path_d[e][s] = w
    
#     dq = []
#     visited = [INF] * (n + 1)
    
#     for n in gates:
#         visited[n] = 0
#         heapq.heappush(dq, [0 ,n])

        
#     while dq:
#         intensity, node = heapq.heappop(dq)

#         if node in summits:
#             answer = [node, intensity]
#             break
                    
#         for next_n,next_w in path_d[node].items():
#             max_w = max(intensity, next_w)
#             if max_w < visited[next_n]:
#                 visited[next_n] = max_w
#                 heapq.heappush(dq, [max_w , next_n])

#     return answer

# 다익스트라 이용
import heapq
from collections import defaultdict
    
INF = int(1e9)
    
def solution(n, paths, gates, summits):
    summits = set(summits)
    answer = []
    path_d = defaultdict(dict)
    temp_intensity = []
    
    for s,e,w in paths:
        path_d[s][e] = w
        path_d[e][s] = w
    
    dq = []
    visited = [INF] * (n + 1)
    
    for n in gates:
        visited[n] = 0
        heapq.heappush(dq, [0 ,n])

        
    while dq:
        intensity, node = heapq.heappop(dq)

        if node in summits:
            temp_intensity.append([node, intensity])
            continue
            
        if intensity > visited[node]:
            continue
                    
        for next_n,next_w in path_d[node].items():
            max_w = max(intensity, next_w)
            if max_w < visited[next_n]:
                visited[next_n] = max_w
                heapq.heappush(dq, [max_w , next_n])

    
    answer = min(temp_intensity, key = lambda x: (x[1], x[0]) )
    return answer