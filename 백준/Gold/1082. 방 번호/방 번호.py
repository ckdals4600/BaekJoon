n = int(input())
p = list(map(int, input().split()))
m = int(input())

table = [['' for _ in range(m + 1)] for _ in range(n)]

def makeMaxNum(num1,num2):
    nums = [int(d) for d in num1]
    nums.append(num2)
    nums = sorted(nums,reverse=True)
    num = ''.join(map(str, nums))
    return num

def findMaxRightIdx(strs):
    nums = [int(i) if i != '' else -1 for i in strs]
    max_num = max(nums)
    idx = len(nums) - 1 -nums[::-1].index(max_num)
    return idx

for i in range(n):
    for j in range(m + 1):
        if p[i] <= j:
            strs = [makeMaxNum(table[i][j-p[i]], i)]
            for k in range(i):
                strs.append(table[k][j])
                strs.append(makeMaxNum(table[k][j-p[i]], i))
            idx = findMaxRightIdx(strs)
            table[i][j] = strs[idx]
        else:
            table[i][j] = table[i-1][j]
            

# for i in table:
#     print(i)            
print(int(table[n-1][m]))