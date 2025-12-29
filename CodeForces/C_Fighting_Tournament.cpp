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
        int n, q;
        cin >> n >> q;
        vector<int> a(n), p(n);
        for (auto &x : a)
        {
            cin >> x;
        }
        p[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            p[i] = max(p[i - 1], a[i]);
        }
        int maxi = max_element(a.begin(), a.end()) - a.begin();

        while (q--)
        {
            int idx, k; // index, rounds.
            cin >> idx >> k;
            idx--;
            if (p[idx] > a[idx])
            {
                cout << "0\n";
                continue;
            }
            if (a[idx] == a[maxi])
            {
                if (idx == 0)
                {
                    cout << k << "\n";
                    continue;
                }
                k -= (idx);
                if (k >= 0)
                {
                    cout << 1 + k << "\n";
                    continue;
                }
            }

            int count = ((k - idx >= 0 && idx != 0) ? 1 : 0);
            k -= idx;
            if (idx < 0)
            {
                cout << count << "\n";
                continue;
            }
            int lidx = upper_bound(p.begin(), p.end(), a[idx]) - p.begin();
            count += min(k, lidx - idx - 1);
            cout << max(count,0) << "\n";
        }
    }
    return 0;
}