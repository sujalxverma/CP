#include "bits/stdc++.h"
using namespace std;
using ll = long long;

bool check(const vector<int> &x, const vector<int> &y, long long mid)
{
    int n = (int)x.size();
    int m = (int)y.size();

    for (int i = 0; i < n - 1; i++)
    {
        ll rx0 = x[0];
        ll rx1 = x[i];
        ll bx0 = x[i + 1];
        ll bx1 = x[n - 1];
        ll x0 = x[0];
        ll x1 = x[i];
    
        for (int j = 0; j < m - 1; j++)
        {

            {
                ll ry = y[0];
                ll ry1 = y[j];
               
                ll by0 = y[j + 1], by1 = y[m - 1];

                bool ok = true;
                if ((rx1 - rx0) * ry1 > mid)
                    ok = false;
                if ((ry1 - ry) * rx1 > mid)
                    ok = false;
                if ((bx1 - bx0) * by1 > mid)
                    ok = false;
                if ((by1 - by0) * bx1 > mid)
                    ok = false;

                if (ok)
                    return true;
            }

            {
                ll ry = y[j + 1];
                ll ry1 = y[m - 1];
                ll by0 = y[0], by1 = y[j];

                bool ok = true;
                if ((rx1 - rx0) * ry1 > mid)
                    ok = false;
                if ((ry1 - ry) * rx1 > mid)
                    ok = false;
                if ((bx1 - bx0) * by1 > mid)
                    ok = false;
                if ((by1 - by0) * bx1 > mid)
                    ok = false;

                if (ok)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> x(n), y(m);
        for (auto &a : x)
            cin >> a;
        for (auto &b : y)
            cin >> b;

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        ll s = 0, e = 1e18, ans = 0;
        while (s <= e)
        {
            ll m = s + (e - s) / 2;
            if (check(x, y, m))
            {
                ans = m;
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
