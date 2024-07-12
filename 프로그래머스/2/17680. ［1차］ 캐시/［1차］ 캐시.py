from collections import deque

# 캐쉬 크가 -> 최대 30 -> 선형 탐색해도 최대 시간 30 * 100,000 -> 3,000,000
def solution(cacheSize, cities):
    answer = 0
    
    cache = deque()
    cache_set = set()
    
    for city in cities:
        city = city.lower()
        if city in cache_set:
            answer += 1
            cache.remove(city)
            cache.appendleft(city)
        else:
            answer += 5
            cache.appendleft(city)
            cache_set.add(city)
            if len(cache) > cacheSize:
                cache_set.remove(cache.pop())
    
    return answer