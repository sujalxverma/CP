#include "bits/stdc++.h"
using namespace std;
const long long inf = 1e18;
const long long neginf = -1e18;
void solve() {
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (auto &X : a) {
        cin >> X;
    }

    vector<long long> b(m);
    for (long long i = 0; i < m; i++)
        cin >> b[i];
    int cnt = 0;
    int ci = 0;
    int cj = 0;
    while (ci < n && cj < m) {
        if (a[ci] >= b[cj]) {
            cj++;
            ci++;
            cnt++;
        } else {
            ci++;
        }
    }
    if (cnt == m) {
        cout << "0\n";
        return;
    }
    vector<long long> p(m), s(m);
    int j = 0;
    for (int i = 0; i < m; i++) {
        while (j < n && a[j] < b[i])
            j++;
        p[i] = j++;
    }
    j = n - 1;
    for (int i = m - 1; i >= 0; i--) {
        while (j >= 0 && a[j] < b[i])
            j--;
        s[i] = j--;
    }
    long long ans = inf;
    for (int i = 0; i < m; i++) {
        long long v1 = (i == 0 ? -1 : p[i - 1]);
        long long v2 = (i == m - 1 ? n : s[i + 1]);
        if (v1 < v2) {
            ans = min(ans, b[i]);
        }
    }
    cout << (ans == inf ? -1 : ans) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}