#include "bits/stdc++.h"
using namespace std;
#define int long long
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp((1 << n), 0LL);
    for (int i = 0; i < n; i++) {
        dp[(1 << i)] = a[i];
    }

    vector<int> gmask(1 << n); // precompute gcd for a particular mask.
    for (int mask = 1; mask < (1 << n); mask++) {
        int g = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                g = gcd(g, a[i]);
        gmask[mask] = g;
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        if (mask == (1 << n) - 1) {
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                continue;
            }

            dp[mask | (1 << i)] = max(dp[mask | (1 << i)], gcd(gmask[mask], a[i]) + dp[mask]);
        }
    }
    // for (int i = 0; i < (1 << n); i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}