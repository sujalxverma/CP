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
        string a, b, c;
        cin >> a >> b >> c;
        string p = "", q = "", r = "";
        for (int i = 0; i < n; i++)
        {
            if (b[i] != c[i])
            {
                p += a[i];
                q += b[i];

                r += c[i];
            }
        }
        int z_zero = 0;
        int z_one = 0;
        int o_zero = 0;
        int o_one = 0;

        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == q[i] && p[i] == '0')
            {
                z_zero++;
            }
            else if (p[i] == q[i] && p[i] == '1')
            {
                o_one++;
            }
            else if (p[i] != q[i] && p[i] == '0')
            {
                z_one++;
            }
            else if (p[i] != q[i] && p[i] == '1')
            {
                o_zero++;
            }
        }
        int min_1 = min(z_zero, z_one);
        int min_2 = min(o_zero, o_one);
        z_zero -= min_1;
        z_one -= min_1;
        o_zero -= min_2;
        o_one -= min_2;
        int ans = 0;
        int min_3 = min(o_one, z_zero);
        int min_4 = min(z_one, o_zero);
        z_zero -= min_3;
        z_one -= min_4;
        o_zero -= min_4;
        o_one -= min_3;
        ans = z_zero + z_one + o_zero + o_one + min_3 + min_4;
        cout << ans << "\n";
    }
    return 0;
}