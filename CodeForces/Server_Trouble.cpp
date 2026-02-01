#include "bits/stdc++.h"
using namespace std;
using ll = long long;

/*
1. 3 <= k <= n <= 1e9.
2. Only case important is k < (n/2)
3. When we place k servers on a circle, then k gaps are created.
4. each_gap_dist-> D = (n+k-1)/k , i.e. ceil(n/k);
5. say each gap, is (D-1) , then (D-1)*k < n.
6. means this extra_space ->  n - (D-1)*k , needs to be fullfiled by placing servers at distance D.
7. Thus creating X = n - (D-1)*k , X pairs having distance D.
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n, k;
        cin >> n >> k;
        if (k == n)
        {
            cout << 1 << " " << n << "\n";
            continue;
        }

        if (k == (n / 2))
        {
            if (n % 2 == 0)
            {
                cout << 2 << " " << n / 2 << "\n";
            }
            else
            {
                cout << (n + k - 1) / k << " " << 1 << "\n";
            }

            continue;
        }

        if (k > (n / 2))
        {
            if (n % 2 == 0)
            {
                cout << 2 << " " << (n / 2) - (k - (n / 2)) << "\n";
            }
            else
            {
                cout << 2 << " " << (n - k) << "\n";
            }
            continue;
        }
        if (k < (n / 2))
        {
            ll gaps_dist = (n + k - 1) / k;
            ll extra_pairs = n - (gaps_dist - 1) * (k);
            cout << gaps_dist << " " << extra_pairs << "\n";
        }
    }
    return 0;
}