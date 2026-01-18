#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    ll total_sum = 0;
    for (auto &x : a)
    {
        cin >> x;
        total_sum += x;
    }
    if(total_sum < x){
        cout<<"-1\n";
        return 0;
    }
    ll sum = 0;

    sort(begin(a), end(a));
    for (ll i = 0; i < k; i++)
    {
        sum += a[i];
    }
    
    if (sum < x)
    {
        cout << "-1\n";
    }
    else
    {
        ll s = 0;
       for(int i = k-1 ; i >= 0 ; i--){
        s += a[i];
        if(s >= x){
            cout<<n-i<<"\n";
            return 0;
        }
       }

       cout<<"-1\n";
    }
    return 0;
}