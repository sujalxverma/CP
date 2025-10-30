def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    # Build prefix sum
    prefix = [0]
    for num in a:
        prefix.append(prefix[-1] + num)
    ans = float('inf')
    idx = -1
    # Check all k-length subarrays
    for i in range(n - k + 1):
        if (prefix[i + k] - prefix[i] < ans):
            idx = i
            ans = prefix[i + k] - prefix[i] 
        
    print(idx+1)

solve()
