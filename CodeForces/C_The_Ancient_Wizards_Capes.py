mod = 676767677


def check(cape, a):
    vis = 1
    n = len(a) - 1
    for i in range(2, n + 1, 1):

        if cape[i] == 1:
            vis += 1

    if vis != a[1]:
        return False

    for i in range(1, n , 1):
        if cape[i] == 1 and cape[i + 1] == 1:
            vis -= 1
        elif cape[i] == 0 and cape[i + 1] == 0:
            vis += 1
        if a[i + 1] != vis:
            return False
    return True


def solve():

    n = int(input())
    a = [0] + list(map(int, input().split()))


    for i in range(1, n , 1):
        if abs(a[i + 1] - a[i]) > 1:
            print(0)
            return
    ans = 0
    for start in range(0, 2, 1):
        cape = [0] * (n + 1)
        cape[1] = start

        for i in range(2, n + 1, 1):
            if a[i] == a[i - 1]:
                cape[i] = 1 - cape[i - 1]
            else:
                cape[i] = cape[i - 1]

        if check(cape,a):
            ans += 1

    print(ans)

    return


t = int(input())
for _ in range(t):
    solve()
