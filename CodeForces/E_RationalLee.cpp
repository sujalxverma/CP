#include "bits/stdc++.h"
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++)
        cin >> b[j];

    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());

    ll maxSum = 0;
    int j = 0;
    int k = -1;
    for (int i = 0; i < m; i++)
    {
        if (b[i] == 1)
        {
            maxSum += 2 * a[j];
            j++;
            b[i]--;
        }
        else
        {
            k = i;
            break;
        }
    }
    if (k == -1)
    {
        cout << maxSum << "\n";
        return;
    }
    // give max to each.

    for (int i = k; i < m; i++)
    {
        maxSum += a[j];
        j++;
        b[i]--;
    }

    // now give b[i] remaining minimums to each.

    int back = n - 1;
    for (int i = m - 1; i >= k; i--)
    {
        maxSum += a[back];
        back -= (b[i]);
        b[i] = 0;
    }

    cout << maxSum << "\n";
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