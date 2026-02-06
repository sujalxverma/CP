def f(a, c, d, mid):

    n = len(a)
    sum = 0
    cnt = 0
    for i in range(n):
        if cnt > d:
            return False
        cnt += 1 + ((d - (i + 1)) // (mid + 1))
        sum += a[i] + ((((d - (i + 1)) // (mid + 1)) * a[i]))

        if sum >= c and cnt <= d:
            return True

    return False


def solve():

    n, c, d = map(int, input().split())

    a = list(map(int, input().split()))
    a.sort(reverse=True)
    sum = 0
    for i in range(n):
        sum += a[i]
        if i + 1 <= d and sum >= c:
            print("Infinity")
            return

    s = 0
    e = 10**10
    ans = -1
    while s <= e:
        mid = s + (e - s) // 2

        if f(a, c, d, mid):
            ans = mid
            s = mid + 1
        else:
            e = mid - 1

    if ans == -1:
        print("Impossible")
    else:
        print(ans)

    return


t = int(input())
for _ in range(t):
    solve()
