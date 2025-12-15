#include "bits/stdc++.h"
using namespace std;

/*
1. Using Chicken McNugget Theorerm,
2. If gcd(a,b) == 1, then ax+by can only represent numbers , > (ab - a - b).
3. For numbers less, simply use brute force, when a = 11 and b = 111.
*/

void solve()
{
    int n;
    cin >> n;
   
    if( n > (11*111 - 11 - 111)){
        cout<<"YES\n";
        return ;
    }
    
    for(int i = 0 ; i < 100 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            if(i*11 + j*111 == n){
                cout<<"YES\n";
                return ;
            }
        }
    }
    cout<<"NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}