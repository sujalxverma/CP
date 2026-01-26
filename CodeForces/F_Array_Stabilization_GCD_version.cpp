#include "bits/stdc++.h"
using namespace std;
vector<int> a;
vector<vector<int>> st;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
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
        a.resize(2 * n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = n; i < 2 * n; i++)
            a[i] = a[i - n];
        int max_row = floor(log2(2 * n));
        st.assign(max_row + 1, vector<int>(2 * n, 0));

        st[0] = a;
        for (int i = 1; i <= max_row; i++)
        {
            for (int j = 0; j + (1 << i) <= 2 * n; j++)
            {
                st[i][j] = gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }

        int ans = 0;
        for (int i = 0; i <= n - 1; i++)
        {
            int len = i + 1;
            int k = floor(log2(len));
            bool f = true;
            int base = gcd(st[k][0], st[k][len - (1 << k)]);
            for (int j = 1; j < n; j++)
            {
                if (base != gcd(st[k][j], st[k][j + len - (1 << k)]))
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}