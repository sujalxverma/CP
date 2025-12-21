#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> f(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        f[a[i]]++;
    }
    // case1 : k is absent.
    if (f[k] == 0)
    {
        int count = 0;
        for (int i = 0; i < k; i++)
        {
            if (f[i] != 0)
            {
                count++;
            }
        }
        cout << k + 1 - count << "\n";
        return;
    }

    // case2 : k is present.
    vector<int> idx; // stores indices of k.
    for (int i = 0; i < n; i++)
    {
        if (a[i] == k)
        {
            idx.push_back(i);
        }
    }
    // check b/w two consecutive k's, [1 to i1-1] , then [i1+1 , i2-1], ... , [im+1 , n] and so on.

    int ans = INT_MAX;

    for (int i = 0; i <= (int)idx.size(); i++)
    {
        int L = (i == 0 ? 0 : idx[i - 1] + 1);
        int R = (i == (idx.size()) ? n - 1 : idx[i] - 1);

        if (L > R)
        {
            ans = min(ans, k + 1);
            continue;
        }

        vector<int> seen(k, 0);
        int distinct = 0;

        for (int j = L; j <= R; j++)
        {
            if (a[j] < k && !seen[a[j]])
            {
                seen[a[j]] = 1;
                distinct++;
            }
        }

        ans = min(ans, (k - distinct) + 1);
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