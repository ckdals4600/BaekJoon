# 문자열 순서 문제?
# 연결리스트 사용하면 될듯
from collections import defaultdict, deque
import math


def solution(expression):
    ex = []
    is_ex = set()
    
    num = 0
    for c in expression:
        if c in "+-*":
            ex.append(num)
            ex.append(c)
            is_ex.add(c)
            num = 0
        else:
            num = num * 10 + int(c)
    
    ex.append(num)
    
    def cau(order):
        ex_temp = deque(ex)
        for e in order:
            ex2 = deque()
            while ex_temp:
                c = ex_temp.popleft()
                
                if  c == e:
                    if c == "+":
                        c = ex2.pop() + ex_temp.popleft()
                    elif c == "-":
                        c = ex2.pop() - ex_temp.popleft()
                    elif c == "*":
                        c = ex2.pop() * ex_temp.popleft()
                ex2.append(c)
            ex_temp = ex2    
        ret = ex_temp.pop()
        return ret if ret > 0 else -ret 
    
    print(ex)
    
    order = ''
    for i in list(is_ex):
        order += i 
    
    answer = 0
    
    if len(order) == 1:
        answer = cau(order)
    elif len(order) == 2:
        answer = max(cau(order),cau(order[::-1]))
    elif len(order) == 3:
          for i in ["+*-","+-*","-+*","-*+","*-+","*+-"]:
                ret = cau(i)
                answer = max(answer, ret)
    return answer