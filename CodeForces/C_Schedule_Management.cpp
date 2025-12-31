#include "bits/stdc++.h"
using namespace std;
using ll = long long;
bool check(vector<int> &f, int m)
{
    int n = (int)f.size();
    ll free = 0;
    for (int i = 0; i < n; i++)
    {

        // if a candidate is master, then it may have some time remain, so he can use it too.
        free += max(0, (m - f[i]) / 2);
    }

    for (int i = 0; i < n; i++)
    {

        if (f[i] > m)
        {
            int diff = f[i] - m;
            if (diff <= free)
            {
                free -= diff;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

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
        int m;
        cin >> m;
        vector<int> a(m);
        vector<int> f(n, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];

            f[a[i] - 1]++;
        }
        sort(f.rbegin(), f.rend());

        int s = 1;
        int e = 1e7;
        int ans = 0;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (check(f, mid))
            {

                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}