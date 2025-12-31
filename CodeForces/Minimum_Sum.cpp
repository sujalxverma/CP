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
        int n;
        cin >> n;

        vector<ll> a(n);
        ll sum = 0;
        for (auto &x : a)
        {
            cin >> x;
            sum += x;
        }

        sort(a.begin(), a.end());

        ll num = 0;
        for (int bit = 0; bit < 31; bit++)
        {
            int ones = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] & (1LL << bit))
                    ones++;
            }
            int zeros = n - ones;
            if (ones >= zeros)
                num |= (1LL << bit);
        }

        ll total = 0;
        for (int i = 0; i < n; i++)
        {
            total += (a[i] ^ num);
        }

        cout << min(total, sum) << "\n";
    }
    return 0;
}
