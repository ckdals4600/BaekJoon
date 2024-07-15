# 자식 노드 1에 대해 부모 노드는 0 이 될수 없다!

import math
from collections import deque

def solution(numbers):
    answer = []
    
    def changeBi(number):
        bi = bin(number)[2:]
        
        sq = math.log2(len(bi)+1)
        if sq != sq//1:
            addZero = int(2**((sq//1) + 1)) - (len(bi) + 1)
            bi = "0" * addZero + bi
            
        return bi
    
    def binaryTree(bi, parent):
        mid_idx = len(bi)//2
        mid = bi[mid_idx]
        
        if mid == "0" and parent == "-1":
            return 0
        
        if mid == "1" and parent == "0":
            return 0
        
        if mid_idx == 0:
            return 1
        
        return binaryTree(bi[:mid_idx], mid) & binaryTree(bi[mid_idx+1:], mid)
    
    for number in numbers:
        bi = changeBi(number)
        answer.append(binaryTree(bi, "-1"))
        
    return answer
