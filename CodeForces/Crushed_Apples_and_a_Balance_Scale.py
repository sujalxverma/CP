import sys
input = lambda: sys.stdin.readline().strip()

def ints(): return list(map(int, input().split()))
def int1(): return int(input())

# constants
INF = int(1e18)

def solve():
    # your logic here
    m , n = map(int, input().split())
    if m < n :
        print('NO')
        return

    if(m == n):
        print('YES')
        return
    
    while( (m % 2) == 0):
        m = m // 2
        
    if( (n % m) == 0):
        print('YES')
        return
    print('NO')
    
    return

if __name__ == "__main__":
    t = int1()
    for _ in range(t):
        solve()