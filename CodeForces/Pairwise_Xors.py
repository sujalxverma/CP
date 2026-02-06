import sys
input = lambda: sys.stdin.readline().strip()

def int1(): 
    return int(input())

INF = int(1e18)

def solve():
    x = int1()

    # x == 0 or power of two => impossible
    if  (x & (x - 1)) == 0:
        print(-1)
        return

    if (x%2):
        print(-1)
        return

    half = x // 2
    i = 1

    while i < half:
        if i + half + (i ^ half) == x:
            print(i, half, 0)
            return
        i *= 2

    

if __name__ == "__main__":
    t = int1()
    for _ in range(t):
        solve()
