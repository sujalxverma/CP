#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, g, b;
        cin >> n >> g >> b;

        ll ans = 0;
        ll count = (n + 1) / 2;
        ll rem = n - count;
        ans += (count / g) * (g+b);

        if(count % g == 0){
            ans -= b;
        }else{
            ans += (count % g);
        }
        cout<<max(n,ans)<<"\n";

    }
    return 0;
}