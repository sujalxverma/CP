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
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        vector<vector<int>> p(n + 1, vector<int>(31, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                if (a[i] & (1 << j))
                {
                    p[i][j] = p[i - 1][j] + 1;
                }
                else
                {
                    p[i][j] = p[i - 1][j];
                }
            }
        }

        int q;
        cin >> q;
        while (q--)
        {
            int l, k;
            cin >> l >> k;
            if (a[l] < k)
            {
                cout << -1 << " ";
                continue;
            }
            int s = l;
            int e = n;
            int ans = l;
            while (s <= e)
            {
                int num = 0;
                int m = (s + e) / 2;

                for (int i = 0; i < 31; i++)
                {
                    if (p[m][i] - p[l - 1][i] == (m - l + 1))
                    {
                        num += (1 << i);
                    }
                }

                if (num >= k)
                {
                    s = m + 1;
                    ans = max(ans, m);
                }
                else
                {
                    e = m - 1;
                }
            }
            cout << ans << " ";
        }
        cout << "\n";
    }

    return 0;
}