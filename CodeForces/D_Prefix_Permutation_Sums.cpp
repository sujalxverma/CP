#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2 != 0) {
            a[i] = -a[i];
        }
    }

    vector<int> p(n);
    p[0] = a[0];
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] + a[i];
    }

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[p[i]]++;
    }
    for (auto x : mp) {
        if (x.second > 1) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << "\n";
    return;
}
int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}