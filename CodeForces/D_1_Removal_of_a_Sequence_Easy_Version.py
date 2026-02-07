inf = 10**12 + 1


def solve():
    x, y, k = map(int, input().split())
    s = 1
    e = inf

    ans = -1
    while s <= e:
        m = s + (e - s) // 2
        len = m - 1
        for i in range(x):
            len -= len // y

        if len + 1 > k:
            e = m - 1

        else:
            s = m + 1

    if e == inf:
        print(-1)
        return

    print(e)
    return


t = int(input())

for _ in range(t):
    solve()
