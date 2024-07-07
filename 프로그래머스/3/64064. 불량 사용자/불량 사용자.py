# user_id 크기 8 이하 문자열 크기 8 이하 그냥 해도 시간초과 안나겠는데 ?
# 백트래킹 사용
# 비트 마스킹 사용

# find 함수 사용해보기
# https://devjss.com/python-find-all-string-in-string/
# 원하는 위치 변경
# https://gbjeong96.tistory.com/25

from collections import defaultdict


def solution(user_id, banned_id):
 
    
    banneds = defaultdict(list) #* 위치
    
    for ban in banned_id:
        start = -1
        idxs = []
        
        while True:
            start = ban.find("*", start + 1)
            if start == -1:
                break
            
            idxs.append(start)
        
        banneds[ban] = idxs
    
    possibel_ban = []
    
    for ban in banned_id:
        possible = []
        
        for user in user_id:
            if len(ban) == len(user):
                
                temp_user = list(user)
                for i in banneds[ban]:
                    temp_user[i] = "*"
                temp_user = ''.join(temp_user)
                
                if ban == str(temp_user):
                    possible.append(user)
        
        possibel_ban.append(possible)
        
    user_bit = {}
    for i in range(len(user_id)):
        user_bit[user_id[i]] = i
        
    chk = set()
    final_list = set()
    answer = 0

    def backtracking(bits):
        if len(chk) == len(banned_id):
            if bits not in final_list:
                final_list.add(bits)
            return
        
        
        for ban_id in possibel_ban[len(chk)]:
            
            if ban_id in chk:
                continue

            chk.add(ban_id)
            backtracking(bits | (1 << user_bit[ban_id]))
            chk.remove(ban_id)
    
    backtracking(0)            
    answer = len(final_list)
    return answer