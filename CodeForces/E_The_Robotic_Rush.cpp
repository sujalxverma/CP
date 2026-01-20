#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<ll> a;
vector<ll> b;
const ll inf = -1e18;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        a.resize(n);
        b.resize(m);
        set<ll> pos;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            pos.insert(b[i]);
        }
        string s;
        cin >> s;
        sort(begin(b), end(b));
        vector<ll> prefix(n);
        prefix[0] = (s[0] == 'L' ? -1 : 1);
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + (s[0] == 'L' ? -1 : 1);
        }

        // traversing robots.
        for (int i = 0; i < n; i++)
        {
            // nearest spike left to robot.
            ll left = inf;
            ll right = 1e18;
            if (b[0] > a[i])
            {
                // no leftmost exist.
            }
            else
            {
                auto idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
                left = b[idx - 1];
            }
            if (b[m - 1] < a[i])
            {
                // no rightmost exist
            }
            else
            {
                auto idx = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
                right = b[idx];
            }
        }

        cout << "\n";
    }
    return 0;
}