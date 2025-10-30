import sys
input = lambda: sys.stdin.readline().strip()

def ints(): return list(map(int, input().split()))
def int1(): return int(input())


# constants
INF = int(1e18)
MOD = 998244353 


def factorial(n):
    result = 1
    for i in range(2 ,n+1,1):
        result *= i
    return result

def nCr(n,r):
    if r > n:
        return 0
    return (factorial(n) / (factorial(r) * (factorial(n-r))))

def solve():
    # your logic here
    s = input()
    n = len(s)
        
    blocks = []
    cnt = 1
    for i in range(1,n):
        if s[i] == s[i-1]:
            cnt+=1
        else:
            blocks.append(cnt)
            cnt = 1
            
    blocks.append(cnt)    
        
    ans = 1
    k = n
    for block in blocks:
        ans = ((ans%MOD) * (block))%MOD
        k-=1
    
    for i in range(1, k+1):
        ans = ((ans%MOD) * (i))%MOD
    
    print(k,ans)
    
    pass

if __name__ == "__main__":
    t = int1()
    for _ in range(t):
        solve()