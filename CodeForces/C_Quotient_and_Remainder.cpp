#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        ll b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);

        int ans = 0;
        int s = 0;
        int e = n - 1;

        while (s <= e)
        {
            int m = s + (e - s) / 2;

            bool f = true;
            for (int i = 0; i <= m; i++)
            {
                if ((a[i] + 1) * (b[m - i] + 1) - 1 > k)
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                s = m + 1;
                ans = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}