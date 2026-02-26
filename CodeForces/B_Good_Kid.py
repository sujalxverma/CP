t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        a[i] = a[i] +  1
        product = 1
        for j in range(n):
            product *= a[j]
        a[i] = a[i] -  1
        ans = max(ans , product)

    print(ans)
