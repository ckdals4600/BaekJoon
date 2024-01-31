n = int(input())
exist_check = {}

n_list = list(map(int, input().split()))

for i in n_list:
    exist_check[i] = 1;

m = int(input())
m_list = list(map(int, input().split()))

for i in m_list:
    print(exist_check.get(i,0))