#include "bits/stdc++.h"
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> f(32, 0);
        for (int i = 0; i < n; i++) {
            f[floor(log2(a[i])) + 1]++;
        }
        int ans = 0;
        for (int i = 0; i <= 30; i++) {
            ans += (f[i] * (f[i] - 1)) / 2;
        }
        cout << ans << "\n";
    }

    return 0;
}