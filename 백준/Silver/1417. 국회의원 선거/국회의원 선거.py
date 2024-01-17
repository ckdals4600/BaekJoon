num = int(input())

dason=int(input())
votes=[]
get = 0

for _ in range(num-1) :
    a = int(input())
    if a >= dason:
        votes.append(a)

while votes and max(votes) >= dason:
    dason += 1
    get += 1
    votes[votes.index(max(votes))] -= 1

print(get)