#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;

    set<ll> s;
    s.insert(0); // initial value
    vector<ll> ans;

    ll sum = 0;
    map<ll, ll> mp;
    mp[0] = a[0]; // mp[x] = best distance to nearest neighbor (?)
    sum += 2 * a[0];
    mp[a[0]] = a[0];
    s.insert(a[0]);
    ans.push_back(sum);

    for (ll i = 1; i < n; i++)
    {
        ll x = a[i];
        s.insert(x);

        mp[x] = 1e9;

        auto it = s.find(x);
        ll d1 = 1e10;
        ll d2 = 1e10;

        ll d = 1e9;

        // -----------------------
        // LEFT SIDE
        // -----------------------
        if (it != s.begin())
        {
            auto left = it;
            --left;

            ll dist = abs(x - *left);
            d1 = min({mp[x], dist});

            if (mp[*left] > dist)
            {

                sum -= mp[*left];
                sum += dist;

                mp[*left] = dist;
            }
        }

        // -----------------------
        // RIGHT SIDE
        // -----------------------
        auto right = it;
        ++right;
        if (right != s.end())
        {
            ll dist = abs(x - *right);
            d2 = min({d1,mp[x], dist});
            
            if (mp[*right] > dist)
            {

                sum -= mp[*right];
                sum += dist;

                mp[*right] = dist;
            }
        }
        mp[x] = min(d1, d2);
        sum += mp[x]; // add best distance for x

        ans.push_back(sum);
    }

    for (auto x : ans)
        cout << x << "\n";

    return 0;
}
