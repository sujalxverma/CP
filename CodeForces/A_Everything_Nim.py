

def solve():
    n = int(input())
    a = list(map(int,input().split()))
    maxi = max(a)
    a.sort()
    mini = 1
    
    for c in a:
        if mini == c:
            mini += 1

    if mini > maxi:
        if maxi % 2 == 0:
            print("Bob")
        else :
            print("Alice")    
            
    else:
        if mini % 2 == 0:
            print("Bob")
        else :
            print("Alice")    
    pass

t = int(input())

for _ in range(t):
    solve()