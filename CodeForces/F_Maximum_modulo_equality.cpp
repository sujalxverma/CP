#include "bits/stdc++.h"
using namespace std;
const int inf = 1e9;

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
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (auto &x : a)
        {
            cin >> x;
        }

        int max_row = log2(n);
        vector<vector<int>> st(max_row + 1, vector<int>(n, 0));
        st[0][0] = 0;
        for (int i = 1; i < n; i++)
        {
            st[0][i] = abs(a[i] - a[i - 1]);
        }
        for (int i = 1; i <= max_row; i++)
        {
            for (int j = 0; j + (1 << i) <= n; j++)
            {
                st[i][j] = gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if (l == r)
            {
                cout << "0 ";
                continue;
            }

            int L = l + 1; // first difference index
            int R = r;     // last difference index

            int len = R - L + 1;
            int k = log2(len);

            int ans = gcd(st[k][L], st[k][R - (1 << k) + 1]);
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}