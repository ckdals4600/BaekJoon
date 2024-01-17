num = int(input())

dason=int(input())
votes= [int(input()) for _ in range(num-1)]
get = 0

while votes and max(votes) >= dason:
    dason += 1
    get += 1
    votes[votes.index(max(votes))] -= 1

print(get)