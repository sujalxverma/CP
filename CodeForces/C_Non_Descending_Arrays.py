import sys

input = lambda: sys.stdin.readline().strip()


def ints():
    return list(map(int, input().split()))


def int1():
    return int(input())


# constants
INF = 998244353


def solve():
    # your logic here
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    ans = 1

    for i in range(n):
        if a[i] > b[i]:
            a[i], b[i] = b[i], a[i]

    for i in range(n):
         if i == 0 or a[i] >= b[i - 1]:
             ans = (ans * 2) % INF


    print(ans)

    pass


if __name__ == "__main__":
    t = int1()
    for _ in range(t):
        solve()
