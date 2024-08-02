def solution(board, skill):
    answer = 0
    m,n = len(board), len(board[0])
    acc_sum = [[0] * (n+1) for _ in range(m+1)]
    
   
        
    for t, r1, c1, r2, c2, degree in skill:
        if t == 1:
            degree = -degree
        r2 = r2 + 1
        c2 = c2 + 1
        acc_sum[r1][c1] += degree
        acc_sum[r1][c2] -= degree
        acc_sum[r2][c1] -= degree
        acc_sum[r2][c2] += degree
        
    for y in range(m+1):
        for x in range(1, n+1):
            acc_sum[y][x] += acc_sum[y][x-1]
    
    for x in range(n+1):        
        for y in range(1, m+1):
            acc_sum[y][x] += acc_sum[y-1][x]\

    for y in range(m):
        for x in range(n):
            if board[y][x] + acc_sum[y][x] > 0:
                answer += 1
    
    return answer