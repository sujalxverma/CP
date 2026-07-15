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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            if (a[i] > i) {
                a[i + 1] += (a[i] - i);
                a[i] = i;
            }
        }
        bool f = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] >= a[i + 1]) {
                f = false;
            }
        }
        if (f) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}