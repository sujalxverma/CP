#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int n;
ll h;
vector<ll> fruits, height;

void solve()
{
    cin >> n >> h;

    fruits.resize(n);
    height.resize(n);

    for (auto &x : fruits)
        cin >> x;
    for (auto &x : height)
        cin >> x;

    ll sum = 0;
    int l = 0;
    int ans = 0;

    for (int r = 0; r < n; r++)
    {
        // break divisibility chain
        if (r > 0 && height[r - 1] % height[r] != 0)
        {
            sum = 0;
            l = r;
        }

        sum += fruits[r];

        while (sum > h)
        {
            sum -= fruits[l];
            l++;
        }

        ans = max(ans, r - l + 1);
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