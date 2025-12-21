#include "bits/stdc++.h"
using namespace std;
using ll = long long;


/*
1. Using binary search on answers.
2. Consider mid to te the time taken to kill boss.
3. for each attack , it will contribute T += (1 + (mid-1)/cost[i]) * dam[i];
*/

bool f(const vector<ll> &dam, const vector<ll> &cost, ll mid, ll H)
{
    __int128 T = 0; // use 128-bit accumulator to avoid overflow
    for (size_t i = 0; i < dam.size(); ++i)
    {
        // number of uses by time mid: 1 + (mid-1)/cost[i]
        ll uses = 1 + (mid - 1) / cost[i];
        __int128 add = (__int128)uses * (__int128)dam[i];
        T += add;
        if (T >= H) return true; // early exit as soon as we reach H
    }
    return false;
}

void solve()
{
    ll h, n;
    cin >> h >> n;
    vector<ll> dam(n), cost(n);
    for (auto &x : dam) cin >> x;
    for (auto &x : cost) cin >> x;

    ll s = 1;
    ll e = (ll)1e18;
    ll ans = 0;
    while (s <= e)
    {
        ll m = s + (e - s) / 2;
        if (f(dam, cost, m, h))
        {
            ans = m;
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }

    cout << ans << "\n";
}


/*
1. Simulated the whole process.
*/
void code(){
    ll h, n;
    cin >> h >> n;
    vector<ll> dam(n), cost(n);
    for (auto &x : dam) cin >> x;
    for (auto &x : cost) cin >> x;

    set<pair<ll,ll>>p;
    for(ll i = 0; i < n ; i++){
        p.insert({1,i});
    }
    ll ans = 0;
    while(h > 0){
        auto val = *p.begin();
        ll idx = val.second;
        ll turn = val.first;
        p.erase(val);
        h -= dam[idx];
        ans = turn;

        p.insert({turn + cost[idx] , idx});


    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) code();
    return 0;
}
