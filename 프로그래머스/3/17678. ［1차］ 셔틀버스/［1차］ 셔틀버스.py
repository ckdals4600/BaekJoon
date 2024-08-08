def solution(n, t, m, timetable):
    
    def toMinute(time):
        h,m = map(int, time.split(":"))
        return h * 60 + m
    
    time_list = [toMinute(t) for t in timetable]
    time_list = sorted(time_list)
    
    suttle = [0] * n
    suttle_crew = [[] for _ in range(n)]
    first = 9 * 60
    
    for minute in time_list:
        idx = (minute-first-1)//t + 1  if minute > first else 0
        
        while idx < n:
            if suttle[idx] < m:
                suttle_crew[idx].append(minute)
                suttle[idx] += 1
                break
            else:
                idx += 1
    
    last_time = first + (n-1) * t if suttle[-1] < m else suttle_crew[-1][-1] - 1
    answer = format(last_time//60, '02') + ":" + format(last_time%60, '02')
    
    return answer