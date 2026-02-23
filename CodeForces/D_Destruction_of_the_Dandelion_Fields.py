t = int(input())
for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    ans = 0
    odd = []
    for i in range(n):
        if nums[i] % 2 == 1:
            odd.append(nums[i])
        else:
            ans += nums[i]

    odd.sort()
    if len(odd) == 0:
        print(0)
        continue
    for i in range((len(odd) // 2), len(odd)):
        ans += odd[i]
    print(ans)
