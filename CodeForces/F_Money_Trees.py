t = int(input())
for _ in range(t):
    n,x = map(int , input().split())
    a = list(map(int , input().split()))
    h = list(map(int , input().split()))
    
    ans = 0
    l = 0
    f = 0
    
    for r in range(n):
        if( r > 0 and (h[r-1] % h[r] != 0)):
            f = 0
            l = r
        
        f += a[r]
        while(f > x):
            f -= a[l]
            l+=1        
    
        ans = max(ans , r-l+1)
        
    print(ans)