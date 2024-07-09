# dp

# deque 슬라이싱
# https://daewoonginfo.blogspot.com/2019/04/python-collections-deque-itertools.html
# set을 그냥 대입하면 깊은 복사가 아닌 앑은 복사다
# 시간 초과

# from collections import deque
# from itertools import islice

# def solution(coin, cards):
#     n = len(cards)
    
#     def checkHand(hands):
#         hand_list = list(hands)
#         for i in hand_list:
#             if n+1 - i in hands:
#                 return i
            
#         return -1
    
#     def back(coin, hands, remain):
        
#         if not remain:
#             return 1
        
        
#         ret = 1
#         cases = [[], [0], [1], [1,0]]
        
#         for case in cases:
#             minus = len(case)
#             if minus > coin:
#                 continue
            
#             temp_hand = set(hands)
            
#             for i in case:
#                 temp_hand.add(remain[i])
            
            
#             chk = checkHand(temp_hand)
#             if chk == -1:
#                 continue
            
#             temp_hand.remove(chk)
#             temp_hand.remove(n+1-chk)
            
            
#             ret = max(ret, back(coin - minus, temp_hand, remain[2:]) + 1)
        
#         return ret
        
#     answer = back(coin, set(cards[:n//3]), cards[n//3:])
#     return answer


# 2
# https://tolerblanc.github.io/programmers/programmers-nplueone-cardgame/
# 그냥 경우 수를 생각
# 어렵다 ....
# 그리드 문제
# 코인 0 -> 기존 손패에서 처리
# 코인 1 -> 기존 손패와 새로운 카드 2장 중 1장으로 처리
# 코인 3 -> 새로운 카드 2장으로 처리
# 근데 만약 내가 코인 1개를 써서 처리하고 다음턴으로 넘어갔을때 새로운 카드를 초기화 안하는 이유는 
# 그전에 코인 1개를 썻다해도 담턴에 그전에 가져온 카드와 새롭게 가져온 카드들로 처리 가능하면 그냥 코인 2개를 제거
# 그냘 해당턴만이 아니라 가져온 카드 더미중에 몇장을 썻냐? 그게 코인 감소 조건인듯

from collections import deque

def solution(coin, cards):
    n = len(cards)
    
    def checkHand(hand1, hand2):
        hand2 = set(hand2)
        for i in hand1:
            if n+1 - i in hand2:
                hand1.remove(i)
                hand2.remove(n+1 - i)
                return i
            
        return 0
    
    
    answer = 1
    hands = cards[:n//3]
    remains = deque(cards[n//3:])
    news = []
    
    while remains:
        news.append(remains.popleft())
        news.append(remains.popleft())
        
        if checkHand(hands,hands):
            pass
        elif coin >= 1 and checkHand(hands,news):
            coin -= 1
        elif coin >= 2 and checkHand(news,news):
            coin -= 2
        else:
            break
        answer +=1
        
        
    
    return answer