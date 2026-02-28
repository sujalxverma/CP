#include "bits/stdc++.h"
using namespace std;
using ll = long long;

/*
-> No two hurdles are consective, mens ri + 1 < l(i+1)
-> 2<= li <= ri <= L-1
-> No power up lie inside hurdle interval.
-> initial power up = 1.
-> Minimum power up acquire to reach end L. (initial power up is not counted).
*/

void solve()
{
    ll n, m, L;
    cin >> n >> m >> L;
    vector<pair<ll, ll>> hurdles(n);
    for (auto &[x, y] : hurdles)
    {
        cin >> x >> y; // x <= y
    }

    vector<pair<ll, ll>> power(m);
    for (auto &[x, y] : power)
    {
        cin >> x >> y;
    }

    vector<pair<ll, ll>> gaps;
    ll s = 1;
    for (int i = 0; i < n; i++)
    {
        gaps.push_back({s, hurdles[i].first - 1});
        s = hurdles[i].second + 1;
    }
    gaps.push_back({s, L});

    ll ans = 0;
    ll jumps = 1;
    priority_queue<ll> pq;

    ll current = 1;
    ll position = 0;
    for (int i = 0; i < n; i++)
    {
        ll current_gap = hurdles[i].second - hurdles[i].first + 1;
        ll pos = hurdles[i].first - 1;
        while (position < m && power[position].first <= pos)
        {
            pq.push(power[position].second);
            position++;
        }

        while (jumps <= current_gap)
        {
            if (pq.empty())
            {
                cout << "-1\n";
                return;
            }
            jumps += pq.top();
            ans++;
            pq.pop();
        }
    }

    cout << ans << "\n";
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