def solve():
    n, k = map(int, input().split())
    if k == n:
        print("YES")
        for i in range(1, n + 1):
            print(i, i, end=" ")
        print()
        return
    if k < n or k >= 2 * n:
        print("NO")
        return
    if 1 + n <= k and k <= 2 * n - 1:
        print("YES")
        delay = k - n
        nums = [2] * (n + 1)
        print("1 2", end=" ")
        nums[1] -= 1
        nums[2] -= 1
        e = 3
        s = 1
        delay -= 1
        while delay > 0:
            print(e, s, end=" ")
            nums[e] -= 1
            nums[s] -= 1
            e += 1
            s += 1
            delay -= 1
        for i in range(1, n + 1):
            while nums[i] > 0:
                print(i, end=" ")
                nums[i] -= 1
        print()
    else:
        print("NO")


t = int(input())
for _ in range(t):
    solve()
