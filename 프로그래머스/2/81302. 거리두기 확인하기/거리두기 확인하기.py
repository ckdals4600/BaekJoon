# 1
# dfs, heapq 사용
from collections import deque

def solution(places):
    
    def dfs(place):
        max_x = len(place[0])
        max_y = len(place)
        
        persons = []
        for j in range(max_y):
            for i in range(max_x):
                if place[j][i] == "P":
                    persons.append([i,j])
        
        for i,j in persons:
            s = deque() # x,y,거리
            visited = [[False] * max_x for _ in range(max_y)]
            
            print("strat : ",i,j)
            s.append([i,j,0])
            
            while s:
                x,y,w = s.popleft()

                if w > 2 or visited[y][x]:
                    continue
                    
                visited[y][x] = True

                n_x = [0,0,1,-1]
                n_y = [1,-1,0,0]

                for i in range(4):
                    c_x = x + n_x[i]
                    c_y = y + n_y[i]


                    if c_x < 0 or c_y < 0 or c_x >= max_x or c_y >= max_y:
                        continue
                        
                    if visited[c_y][c_x] or place[c_y][c_x] == "X":
                        continue

                    if place[c_y][c_x] == "P" and w+1 <= 2:
                        return 0

                    s.append([c_x,c_y,w+1])                
        
        return 1
    
    #print(dfs(places[1]))
    answer = [dfs(place) for place in places]
    return answer