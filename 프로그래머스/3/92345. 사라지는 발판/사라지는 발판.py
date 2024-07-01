#1
#백트래킹 이용
# import sys

# sys.setrecursionlimit(10**6)

# def solution(board, aloc, bloc):
#     INF = int(1e9)
    
#     max_x = len(board[0])
#     max_y = len(board)
        
#     def backtracking(a, b, count, min_count):
#         print("a:",a,",b:",b,",count:",count,",min:",min_count)
    
       
#         if count > min_count:
#             return min_count
        
#         if (a[0] == b[0] and a[1] == b[1]):
#             return count
        
#         m_x = [1,-1,0,0]
#         m_y = [0,0,1,-1]
        
#         is_move = False
                
#         for i in range(4):
#             a_y,a_x = a
#             cur_x = a_x + m_x[i]
#             cur_y = a_y + m_y[i]
            
#             if cur_x < 0 or cur_y < 0 or cur_x >= max_x or cur_y >= max_y:
#                 continue
            
#             if board[cur_y][cur_x] == 0 or (cur_x == b[1] and cur_y == b[0]):
#                 continue
              
#             is_move = True
#             board[a_y][a_x] = 0
#             min_count = min(min_count, backtracking(b, [cur_y, cur_x], count + 1, min_count))
#             board[a_y][a_x] = 1
        
#         return min(count, min_count) if not is_move else min_count 
        
     
#     answer = backtracking(aloc, bloc, 0, INF)
#     return answer

# 2
# MinMax 트리 이용
# 완전 탐색 및 백트래킹 이용
# 반환 값은 게임이 끝날때 턴수
# 홀수 : 첫번쨰 플레이어가 승리, 짝수 : 두번째 플레이어가 승리
# https://blog.encrypted.gg/1032

# import sys

# sys.setrecursionlimit(10**6)

# def solution(board, aloc, bloc):
#     INF = int(1e9)
    
#     x = len(board[0])
#     y = len(board)
            
    
#     def minMax(aloc,bloc,turn):      
#         a_y, a_x, b_y, b_x = aloc, bloc
        
#         if board[a_y][a_x] == 0:
#             return turn
        
#         m_x = [1,-1,0,0]
#         m_y = [0,0,1,-1]
        
#         for i in range(4):
#             cur_x = a_x + m_x[i]
#             cur_y = a_y + m_y[i]
            
#             if cur_x < 0 or cur_y < 0 or cur_x == x or cur_y == y:
#                 continue
            
#             if board[cur_y][cur_x] == 1:
#                 return True
            
#         return False
            
            
        
        
    
    
    
#     answer = backtracking(aloc, bloc, 0)
#     return answer


dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
n, m = 0, 0

def OOB(x, y):
    return x < 0 or x >= n or y < 0 or y >= m

vis = [[0]*5 for _ in range(5)]
block = [[0]*5 for _ in range(5)]

# 현재 상태에서 둘 다 최적의 플레이를 할 때 남은 이동 횟수
# 반환 값이 짝수 : 플레이어가 패배함을 의미, 홀수 : 플레이어가 승리함을 의미
# curx, cury : 현재 플레이어의 좌표, opx, opy : 상대 플레이어의 좌표
def solve(curx, cury, opx, opy):
    global vis, block
    # 플레이어가 밟고 있는 발판이 사라졌다면
    if vis[curx][cury]: return 0
    ret = 0
    # 플레이어를 네 방향으로 이동시켜 다음 단계로 진행할 예정
    for dir in range(4):
        nx = curx + dx[dir]
        ny = cury + dy[dir]
        if OOB(nx,ny) or vis[nx][ny] or block[nx][ny] == 0: continue
        vis[curx][cury] = 1
        
        # 플레이어를 dir 방향으로 이동시켰을 때 턴의 수
        # 다음 함수를 호출할 때 opx, opy, nx, ny 순으로 호출해야 함에 주의
        val = solve(opx, opy, nx, ny)+1
        
        # 방문 표시 해제
        vis[curx][cury] = 0    
        
        # 1. 현재 저장된 턴은 패배인데 새로 계산된 턴은 승리인 경우
        if ret % 2 == 0 and val % 2 == 1: ret = val # 바로 갱신
        # 2. 현재 저장된 턴과 새로 계산된 턴이 모두 패배인 경우
        elif ret % 2 == 0 and val % 2 == 0: ret = max(ret, val) # 최대한 늦게 지는걸 선택
        # 3. 현재 저장된 턴과 새로 계산된 턴이 모두 승리인 경우
        elif ret % 2 == 1 and val % 2 == 1: ret = min(ret, val) # 최대한 빨리 이기는걸 선택
    return ret

def solution(board, aloc, bloc):
    global n,m
    n = len(board)
    m = len(board[0])
    for i in range(n):
        for j in range(m):
            block[i][j] = board[i][j]
    return solve(aloc[0], aloc[1], bloc[0], bloc[1])