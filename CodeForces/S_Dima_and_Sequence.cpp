#include "bits/stdc++.h"
using namespace std;
const int MAX = 1e5 + 2;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int cal[31];
    fill(cal, cal + 31, 0);

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        int cnt = __builtin_popcount(k);
        cal[cnt]++;
    }

    ll ans = 0;
    for (auto it : cal)
    {
        ans += (ll)it * (it - 1) / 2;
    }
    cout << ans << "\n";

    return 0;
}