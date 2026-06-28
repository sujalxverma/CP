#include "bits/stdc++.h"
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    if (a[n - 1] != b[n - 1]) {
        cout << "NO\n";
        return;
    }
    int xorV = a[n - 1];
    int nxorV = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] == b[i]) {
            xorV = a[i];
            nxorV = a[i];
        } else {
            if ((a[i] ^ xorV) == b[i]) {

            } else if ((a[i] ^ nxorV) == b[i]) {

            } else {
                cout << "NO\n";
                return;
            }
            xorV = b[i];
            nxorV = a[i];
        }
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}