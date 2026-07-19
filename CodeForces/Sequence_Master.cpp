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
        vector<int> a(2 * n);
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
            ans += abs(a[i]);
            sum += abs(a[i] - (-1));
        }

        if (n == 1) {
            ans = min(ans, abs(a[1] - a[0]));
        }
        if (n == 2) {
            ans = min(ans, abs(a[0] - 2) + abs(a[1] - 2) + abs(a[2] - 2) + abs(a[3] - 2));
        }
        if (n % 2 == 0) {
            for (int i = 0; i < 2 * n; i++) {
                ans = min(ans, sum - abs(a[i] - (-1)) + abs(a[i] - n));
            }
        }
        cout << ans << "\n";
    }

    return 0;
}