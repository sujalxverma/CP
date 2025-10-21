import sys
input = lambda: sys.stdin.readline().strip()

def ints(): return list(map(int, input().split()))
def int1(): return int(input())

# constants
INF = int(1e18)

def solve():
    # your logic here
    n = int(input())
    s = input()
    
    pra = [0]*n
    prb = [0]*n
    cnt = [0]*n
    
    cnt[0] = (s[0] == 'a')
    
    for i in range(1,n):
        pra[i] = pra[i-1]
        prb[i] = prb[i-1]
        cnt[i] = cnt[i-1]
        
        if(s[i] == 'a'):
            cnt[i] += 1
            prb[i] += i+1-cnt[i]
            
        else:
            pra[i] += cnt[i]
            
    
    sufa = [0]*n
    sufb = [0]*n
    scnt = [0]*n
    
    scnt[n-1] = (s[n-1] == 'a')
    
    for i in range(n-2,-1,-1):
        sufa[i] = sufa[i+1]
        sufb[i] = sufb[i+1]
        scnt[i] = scnt[i+1]
        
        if(s[i] == 'a'):
            scnt[i] += 1
            sufb[i] += n-i-scnt[i]
            
        else:
            sufa[i] += scnt[i]
            
    ans = 1e12
    
    for i in range(n):
        ans = min({ans , pra[i] + sufa[i] , prb[i] + sufb[i]})
        
    print(ans)
    

    pass

if __name__ == "__main__":
    t = int1()
    for _ in range(t):
        solve()