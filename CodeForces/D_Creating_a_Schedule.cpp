#include "bits/stdc++.h"
using namespace std;

using ll = long long;
void rotateRightOnce(std::vector<ll> &v)
{
    if (v.empty())
        return;

    ll last = v.back();
    for (ll i = v.size() - 1; i > 0; --i)
    {
        v[i] = v[i - 1];
    }
    v[0] = last;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for (auto &x : a)
    {
        cin >> x;
    }
    sort(a.rbegin(), a.rend());
    vector<ll> ans;

    int i = 0;
    int j = m - 1;

    while (ans.size() != 6)
    {
        ans.push_back(a[i] / 100);
        ans.push_back(a[j] / 100);
        i++;
        j--;
    }



    if (ans.size() < n)
    {
        ans.push_back(a[i] / 100); // add only one if needed
    }
    for(int i = 0 ; i < 6 - ans.size() ; i++){
        ans.push_back(ans[i]);
    }
    // cout<<ans.size()<<"\n";
    ll count = 0;
    ll s = 0;
    ll e = n - 1;
    ll prev = ans[0];

    for (ll i = 1; i < n; i++)
    {
        count += abs(ans[i] - prev);
        prev = ans[i];
    }
    // count += ans[n - 1];
    for (ll i = 1; i <= n - 1; i++)
    {
        rotateRightOnce(ans);
        prev = ans[0];
        for (ll i = 1; i < n; i++)
        {
            count += abs(ans[i] - prev);
            prev = ans[i];
        }
        // count += ans[n - 1];
    }
    cout << count << "\n";
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