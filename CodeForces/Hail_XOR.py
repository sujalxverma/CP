
t = int(input())
for _ in range(t):
    n,x = map(int,input().split())
    check = [0]*32
    a = list(map(int , input().split()))
    
    for i in range(n):
        
        for j in range(31 , -1 , -1):
            if (a[i] & (1 << j)):
                if(check[j]):
                    check[j] = 0
                    a[i] ^= (1<<j)
                elif(x > 0 and check[j] == 0 and i != n-1):
                    check[j] = 1
                    a[i] ^= (1<<j)
                    x-=1
                    
    for i in range(32):
        if check[i]:
            a[n-1] ^= (1<<i)
            
    
    if (x & 1) and (n == 2):
        a[0] ^= 1
        a[1] ^= 1
    
    for k in a:
        print(k, end=" ")
    print()
        