def solve():
    n, x = map(int, input().split())

    costs = list(map(int, input().split()))
    cashbacks = list(map(int, input().split()))

    a = [[costs[i], cashbacks[i]] for i in range(n)]

    a.sort(key=lambda p: (p[0] - p[1], p[0]))

    ans = 0

    for cost, cashback in a:
        if cost > x:
            continue

        diff = cost - cashback
        if diff <= 0:
            continue

        k = (x - cost) // diff + 1
        if k <= 0:
            continue

        ans += k
        x -= k * diff

    print(ans)


t = int(input())
for _ in range(t):
    solve()
