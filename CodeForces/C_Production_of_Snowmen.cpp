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
        int a[n];
        int b[n];
        int c[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];

        // check for j = 1 how many i are valid.
        int cnt1 = 0;
        for (int j = 0; j < n; j++)
        {
            bool f = true;
            for (int i = 0; i < n; i++)
            {
                if (b[i] <= a[(i + j) % n])
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                cnt1++;
            }
        }
        // check for j = 1 how many k are valid.
        int cnt2 = 0;
        for (int k = 0; k < n; k++)
        {
            bool f = true;
            for (int i = 0; i < n; i++)
            {
                if (b[i] >= c[(i + k) % n])
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                cnt2++;
            }
        }
        cout << 1LL * cnt1 * cnt2 * n << "\n";
    }
    return 0;
}