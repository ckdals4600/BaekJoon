def solution(rows, columns, queries):
    table = [[((i * columns) + j) for j in range(1,columns+1)] for i in range(rows)]
    
    def move(query):
        x1,y1,x2,y2 = query
        
        n = table[x1-1][y1-1]
        ret = n
        for y in range(y1,y2):
            table[x1-1][y],n = n,table[x1-1][y]
            ret = min(n,ret)

        for x in range(x1,x2):
            table[x][y2-1], n = n, table[x][y2-1]
            ret = min(n,ret)

        for y in range(y2-2,y1-2,-1):
            table[x2-1][y], n = n, table[x2-1][y]
            ret = min(n,ret)
            
        for x in range(x2-2,x1-2,-1):
            table[x][y1-1], n = n, table[x][y1-1]
            ret = min(n,ret)
        
        return ret
    
    answer = []
    for query in queries:
        answer.append(move(query))
    
    return answer