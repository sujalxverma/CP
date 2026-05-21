#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        // segment length is k.
        // if for idx, a[idx] >= 2*a[idx+1] , then we cannot consider idx to
        // be part of segment.
        vector<int> f(n + 1, 0);
        for (int i = 1; i <= n - 1; i++) {
            if (a[i] >= 2 * a[i + 1]) {
                f[i] = 1;
            }
        }
        vector<int> p(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + f[i];
        }
        int cnt = 0;
        for (int i = 1; i <= n - k; i++) {
            if (p[i + k - 1] - p[i - 1] == 0) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}