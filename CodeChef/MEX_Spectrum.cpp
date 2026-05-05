#include "bits/stdc++.h"
using namespace std;

int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), f(n + 1, 0), dp(n + 1, 0), p(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            f[a[i]]++;
        }
        p[0] = (f[0] > 0 ? 0 : 1);
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + (f[i] > 0 ? 0 : 1);
        }

        if (f[0]) {
            dp[0] = f[0];
        }

        for (int i = 1; i <= n; i++) {
            dp[i] = p[i - 1] + max(0, f[i] - p[i - 1]);
        }

        for (int i = 0; i <= n; i++) {
            cout << dp[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}