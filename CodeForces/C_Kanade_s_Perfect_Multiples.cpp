#include "bits/stdc++.h"
using namespace std;
using ll = long long;

// all factors of 'n' including 1.
vector<ll> factors(ll n)
{
    vector<ll> ans;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if (i != n / i)
            { // avoid duplicates
                ans.push_back(n / i);
            }
        }
    }
    if (n > 1)
    {
        ans.push_back(1);
        ans.push_back(n);
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    set<ll> s;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        s.insert(a);
    }
    vector<int> nums(s.size(), 0);
    vector<ll> b;
    for (auto x : s)
    {
        b.push_back(x);
    }
    vector<ll> ans;
    ll c = 0;
    for (int i = 0; i < b.size(); i++)
    {
        if (nums[i] == 0)
        {
            // check for multiples.
            ll val = b[i];
            for (ll j = 2 * val; j <= k; j += val)
            {
                auto idx = lower_bound(b.begin(), b.end(), j);
                if (idx == b.end() || *idx != j)
                {
                    cout << -1 << "\n";
                    return;
                }
                nums[idx - b.begin()] = 1;
            }
            nums[i] = 0;
            c++;
        }
    }
    cout<<c<<"\n";
    for (ll i = 0; i < b.size(); i++)
    {
        if (nums[i] == 0)
        {
            cout << b[i] << " ";
        }
    }
    cout << "\n";
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