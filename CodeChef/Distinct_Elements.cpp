#include "bits/stdc++.h"
using namespace std;
const long long mod = 1e9 + 7;
vector<long long> a;

/*
1. Each element can be selected in (fr + 1) times.
2. subtract 1, why ? there is case when none elemenet is selected, ie. empty subsequence.
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        a.resize(n);
        map<long long, long long> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        long long ans = 1;
        for (auto &[x, y] : mp)
        {
            ans = ((ans % mod) * (y + 1) % mod) % mod;
        }
        ans--;
        cout << ans << "\n";
    }
    return 0;
}