t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = [0] * n
    b = [0] * n

    for i in range(n):
        a[i], b[i] = map(int, input().split())

    cnt = 0
    # in 2 sprint, it reaches back at that side.

    start = 0
    pos = 0

    for i in range(n):
        r = a[i] - start
        if pos == b[i]:

            # need even k
            if r % 2 == 0:
                cnt += r
            else:
                cnt += r - 1
        else:
            # need odd k
            if r % 2 == 1:
                cnt += r
            else:
                cnt += r - 1

        start = a[i]
        pos = b[i]

    cnt += m - start

    print(cnt)
