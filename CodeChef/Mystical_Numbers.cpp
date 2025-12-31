#include "bits/stdc++.h"
using namespace std;
using ll = long long;

/*
1. Numbers having same MSB set as in X, ignore those, thus all elements in range except these are the answers.
*/

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int X;
        cin >> X;
        a[i] = X;
    }
    vector<int> zero(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        zero[i] = zero[i - 1] + (a[i] == 0);
    }

    // 2D prefix array of bits.
    vector<vector<int>> prefix;
    vector<int> p(32, 0);
    prefix.push_back(p);
    // n rows , 32 columns
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            prefix.push_back(p);
            continue;
        }
        int msb = 31 - __builtin_clz(a[i]);
        p[msb]++;
        prefix.push_back(p);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        int msb;
        if (x == 0)
        {
            cout << (r - l + 1) - (zero[r] - zero[l - 1]) << "\n";
            continue;
        }

        msb = 31 - __builtin_clz(x);

        // cout<<(prefix[r][msb] - prefix[l - 1][msb])<<"\n";
        cout << r - l + 1 - (prefix[r][msb] - prefix[l - 1][msb]) << "\n";
    }
    // cout<<31 - __builtin_clz(8);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}