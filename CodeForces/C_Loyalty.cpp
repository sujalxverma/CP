#include "bits/stdc++.h"
#include <algorithm>

using namespace std;
using ll = long long;

/*
    if selecting the bigger numbers , increase score then select it, and it to count.
    otherwise select the smaller one. but do not increase count.
*/

void solve()
{
    ll n,x;
    cin >> n >> x;
    vector<ll>a(n+1);
    for(auto i = 1; i <= n ; i++)
    {
        cin >> a[i];
    }
    sort(a.begin()+1,a.end());
    ll sum = 0;
    ll r = n;
    ll count = 0;
    ll l = 1;
    ll prev = 0;
    vector<ll>ans;
    for(ll i = 1; i <= n ; i++){
        if((sum + a[r]) / x  <= prev){
            // add start
            sum += a[l];
            prev = (sum/x);
            ans.push_back(a[l]);
            l++;
        }
        else{
            count += a[r];
            sum += a[r];
            ans.push_back(a[r]);
            r--;
            prev = sum / x;
            
        }
    }
    cout<<count<<"\n";
    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<"\n";
    return ;
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