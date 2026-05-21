#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        vector<int> g(m + 1, 0);
        for (int i = 0; i < n; i++) {
            int r = m - (a[i] % m);
            if (g[r] == 0) {
                if (i + r <= (n - 1)) {
                }
            }
        }
    }
    return 0;
}