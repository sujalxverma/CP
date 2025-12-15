#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int c, m, x;
        cin >> c >> m >> x;

        int mini = min(c, m);
        if (mini == 0)
        {
            cout << "0\n";
            continue;
        }
        if (c == m && m <= x)
        {
            cout << c << "\n";
            continue;
        }
        if (c == m)
        {
            if (x < m)
            {
                cout << (c + m + x) / 3 << "\n";
                continue;
            }
        }
        int ans = mini;
        int rem = abs(c - mini) + abs(m - mini) + max(x - mini, x);
        if (rem >= ans)
        {
            cout << ans << "\n";
        }
        else
        {
            cout << rem + (2 * (ans - rem)) / 3 << "\n";
        }
    }
    return 0;
}