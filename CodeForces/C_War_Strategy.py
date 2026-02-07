def solve():
    n, m, k = map(int, input().split())
    a = b = 0
    f = True

    if k - 1 < n - k:
        k = n - k + 1

    while (a + b + max(a, b) - 1) <= m:
        if f:
            if ((a < k - 1) and ((a + 1 + b + max(a + 1, b) - 1 <= m))):
                a += 1
            else:
                break
            
            f = False

        else:
            if ((b < n - k) and ((a + b + 1 + max(a, b + 1) - 1 <= m))):
                b += 1

            f = True

    print(a + b + 1)

    return


t = int(input())
for _ in range(t):
    solve()
