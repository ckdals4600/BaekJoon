# dp
# from collections import defaultdict

# def solution(enroll, referral, seller, amount):
    
#     graph = defaultdict(list)
#     sell = defaultdict(int)
    
#     for i in range(len(referral)):
#         graph[referral[i]].append(enroll[i])
    
#     for i in range(len(seller)):
#         sell[seller[i]] += amount[i] * 100
    
    
#     fi = {}
    
    
#     def dp(name):
#         if name not in fi:
#             fi[name] = sell[name]
            
#             for low in graph[name]:
#                 donate = int(dp(low) * 0.1)
#                 fi[name] += donate
#                 fi[low] -= donate
                
#         return fi[name]
        
#     dp("-")
    
#     for name in enroll:
#         if name not in fi:
#             fi[name] = 0
            
#     answer = [fi[name] for name in enroll]
#     return answer


from collections import defaultdict
import sys

sys.setrecursionlimit(10**6)

def solution(enroll, referral, seller, amount):
    
    parents = defaultdict(str)
    sell = defaultdict(int)
    
    for i in range(len(referral)):
        parents[enroll[i]] = referral[i]
    
   
    
    fi = defaultdict(int)
    
    def get(name, money):    
        donate = int(money*0.1)
        if parents[name] != "-" and donate != 0:
            get(parents[name], donate)

        fi[name] += money - donate
    
     
    for i in range(len(seller)):
        get(seller[i], amount[i] * 100)
    
            
    answer = [fi[name] for name in enroll]
    return answer