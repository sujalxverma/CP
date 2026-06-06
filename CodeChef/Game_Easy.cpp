#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a) {
        cin >> x.first;
        x.second = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].first > a[j].first) {
                a[j].second++;
            }
        }
    }
    vector<int> b(2 * n + 1, 0);
    sort(rbegin(a), rend(a));
    b[1] = a[0].first;
    int j = 1;
    for (int k = 2; k <= n; k++) {
        if (j < n) {
            b[k] = b[k - 1] + a[j].first;
            b[k] = max(b[k], b[k - 1] - a[j - 1].first + a[j].first + a[j].second);
            j++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
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