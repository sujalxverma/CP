#include "bits/stdc++.h"
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    int g = gcd(a[0], a[1]);
    int count = 0;

    for(int i = 1 ; i < n - 1 ; i++){
        int k = gcd(a[i],a[i+1]);
        if(k < g){
            count++;
            if(i+1 < n){
                g = gcd(a[i],a[i+2]);
            }
            i++;
        }
    }
    if(count > 1){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
    }
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