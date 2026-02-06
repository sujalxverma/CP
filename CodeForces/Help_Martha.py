import sys

input = lambda: sys.stdin.readline().strip()


def ints():
    return list(map(int, input().split()))


def int1():
    return int(input())


# constants
INF = int(1e18)


def solve():
    # your logic here
    s = input()
    fr = [0] * 4
    #  0 -> R , 1 -> L , 2 -> U , 3 -> D
    for ch in s:
        if ch == "R":
            fr[0] += 1

        elif ch == "L":
            fr[1] += 1

        elif ch == "U":
            fr[2] += 1

        else:
            fr[3] += 1


    x,y = map(int , input().split())
    
    q = int(input())
    
    while(q):
        left = right = down = up = 0
        u,v = map(int , input().split())
        if( u <= x):
            left += abs(u - x)
            
        else :
            right += abs(u - x)
        
        if(v <= y):
            down += abs(v - y)
        
        else:
            up += abs(v - y)
        
        #  0 -> R , 1 -> L , 2 -> U , 3 -> D    
        if (right <= fr[0] and left <= fr[1] and up <= fr[2] and  down <= fr[3]):
            print('YES' , left + right + down + up)
        else :
            print('NO')

        q -= 1
        
        
    return


if __name__ == "__main__":
    t = int1()
    for _ in range(t):
        solve()
