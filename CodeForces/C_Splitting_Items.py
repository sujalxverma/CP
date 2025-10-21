def solve():
    n, k = map(int, input().split())       # Read n and k
    vec = list(map(int, input().split()))  # Read the entire vector on one line
    
    vec.sort()
    vec.reverse()
    score = 0
    
    for i in range(n):
        if (i & 1) == 0:
            score += vec[i]
        else:
            score -= vec[i]

    score -= k
    value = (n&1)*vec[n-1]
    print(max(score, value))


t = int(input())
for _ in range(t):
    solve()
