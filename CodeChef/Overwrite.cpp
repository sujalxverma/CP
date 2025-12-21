#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int idx = min_element(b.begin(), b.end()) - b.begin();
    rotate(b.begin(), b.begin() + idx, b.end());
     if (m == 1) {
            for (int i = 0; i < n; ++i) cout << min(a[i], b[0]) << ' ';
            cout << '\n';
            return;
        }
    bool f = true;
    for (int i = 0; i + m <= n; i++)
    {
        if (a[i] < b[0])
            continue;
        else
        {
            f = true;
            if (a[i] == b[0])
            {
                f = false;
                for (int j = 0; j < m; ++j)
                {
                    if (a[i + j] == b[j])
                        continue;
                    if (a[i + j] < b[j])
                        break;
                    f = true;
                    break;
                }
            }
        }

        if (f)
        {
            for (int j = i; j < n; j++)
            {
                a[j] = b[0];
            }
            for (int j = 0; j < m; ++j)
                a[n - 1 - j] = b[m - 1 - j];
            break;
        }
    }
    for (auto x : a)
    {
        cout << x << " ";
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