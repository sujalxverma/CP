#include "bits/stdc++.h"
using namespace std;
using ll = long long;
/*
 * Its possible that for a query x, it was already asked before.
 * So, when a query x is asked for the very first time, then
 * we start from x,2x,3x,... and store ans[x]=(kx).
 * Now query x asked again, then we start from ans[kx], not from start.
 * This is the solution from editorial.
 * Important : Using unordered_map leads to TLE.
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<pair<char, ll>> q;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        char u;
        ll v;
        cin >> u >> v;
        q.push_back({u, v});
    }
    map<ll, ll> ans;
    for (int i = 0; i < n; i++) {
        auto [ch, x] = q[i];
        if (ch == '+') {
            mp[x]++;
            continue;
        }
        ll num = (ans.count(x) ? ans[x] : x);
        while (mp.count(num)) {
            num += x;
        }
        ans[x] = num;
        cout << num << "\n";
    }
    return 0;
}
