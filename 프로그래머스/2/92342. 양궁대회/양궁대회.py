def solution(n, info):
    answer = [-1]

    maxDif = 1
    oppS = 0
    mIdx = -1
    
    for i in range(len(info)):
        if(info[i]):
            oppS += 10 - i
    
    def back(curTB,curS,rmnA,curT, oppS, lIdx):
        nonlocal maxDif, answer, mIdx
        if(rmnA == 0):
            if(curS - oppS > maxDif or (curS - oppS == maxDif and mIdx < lIdx)):
                maxDif = curS - oppS
                answer = curTB[:]
                mIdx = lIdx
            return
        elif(curT == 10):
            if(curS - oppS >= maxDif):
                maxDif = curS - oppS
                answer = curTB[:]
                answer[10] = rmnA
                mIdx = curT
            return
        
        score = 10 - curT
        
        #현재 과녁 맞춤
        if(rmnA > info[curT]):
            curTB[curT] = info[curT] + 1
            back(curTB[:], curS + score, rmnA - curTB[curT], curT + 1, oppS - score if info[curT] > 0 else oppS, curT)
            curTB[curT] = 0
        
        #현재 과녁 안 맞춤
        back(curTB[:], curS, rmnA, curT + 1, oppS, lIdx)

        
        
    back([0] * 11,0,n,0,oppS, mIdx)
    
    return answer