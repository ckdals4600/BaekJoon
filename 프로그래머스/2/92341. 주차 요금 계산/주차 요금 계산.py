# 입력의 길이 최대 1000, 제한 시간 10초 -> O(n^2) 도 가능하다
# Map을 이용해서 풀이, 구현 문제

# 시간 차이 계산 함수, time1 < time2
def timeDif(time1, time2):
    hour1, min1 = map(int,time1.split(':'))
    hour2, min2 = map(int, time2.split(':'))
    
    dif = 0
    dif = (hour2 - hour1) * 60 + (min2 - min1)
    
    return dif
        

def solution(fees, records):
    answer = []
    basic_time, basic_fee, unit_time, unit_fee = fees
    
    car_in = {}
    car_time = {}
    
    for str in records:
        time,car,history = str.split()
        car = int(car)
        
        if history == 'IN':
            car_in[car] = time
        else:
            time = timeDif(car_in[car], time)
            del car_in[car]
            
            if car not in car_time:
                car_time[car] = time
            else:
                car_time[car] += time
    
    for k, v in car_in.items():
        time = timeDif(v, "23:59")
        
        if k not in car_time:
            car_time[k] = time
        else:
            car_time[k] += time
    car_in.clear()
    
    car_time = dict(sorted(car_time.items()))
    
    for car, time in car_time.items():
        fee = basic_fee
        remain_time = time - basic_time
        
        print(car ," : ", remain_time)
        if remain_time > 0:
            fee += ((remain_time // unit_time) + (1 if remain_time % unit_time > 0 else 0)) * unit_fee
        answer.append(fee)
            
             
    return answer