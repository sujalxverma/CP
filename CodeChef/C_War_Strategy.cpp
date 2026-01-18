#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<ll> a;

bool check(ll n, ll m, ll k, ll mid)
{
    // before.
    mid--; // because k(base of captain) is always possible
    
    // get longer side.
    ll max_segment = max(k-1,n-k);
    ll min_segment = min(k-1,n-k);
    // wait for this segement, assuming it is under limit.
    ll time_max = 2*max_segment - 1 ;
    ll time_min = min_segment;

    if(time_max + time_min <= m && max_segment + min_segment <= mid){
        return true;
    } 
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        ll s = 1;
        ll e = n;
        ll ans = 1;
        while (s <= e)
        {
            ll mid = s + (e - s) / 2;
            if (check(n, m, k, mid))
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}