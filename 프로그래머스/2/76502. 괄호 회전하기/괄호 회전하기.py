def is_ok(chk):
    l = []
    m = []
    s = []

    for i in range(len(chk)):
        n = chk[i]
        
        if n == "[":
            l.append(i)
        elif n == "]":
            if not l: return False
        
            if (s and l[-1] < s[-1]) or (m and l[-1] < m[-1]):
                return False
            l.pop()
        elif n == "{":
            m.append(i)
        elif n == "}":
            if not m: return False

            if (s and m[-1] < s[-1]) or (l and m[-1] < l[-1]):
                return False

            m.pop()
        elif n == "(":
            s.append(i)
        elif n == ")":
            if not s: return False

            if (m and s[-1] < m[-1]) or (l and s[-1] < l[-1]):
                return False
            s.pop()

    if s or m or l:
        return False

    return True

def first_chk(chk):
    l_n = 0
    m_n = 0
    s_n = 0
    
    for n in chk:
        if n == "[":
            l_n += 1
        elif n == "]":
            l_n -= 1
        elif n == "{":
            m_n += 1
        elif n == "}":
            m_n -= 1
        elif n == "(":
            s_n += 1
        elif n == ")":
            s_n -= 1
    
    if s_n != 0 or m_n != 0 or l_n != 0:
        return False
    
    return True

def solution(s):
    answer = 0
    if not first_chk(s):
        return answer
    

    n = len(s)
    for i in range(n):
        s = s[1:] + s[0]
        if is_ok(s):
            answer += 1
            
    return answer