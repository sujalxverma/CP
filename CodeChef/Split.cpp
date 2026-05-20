#include "bits/stdc++.h"
using namespace std;
bool check(int x, string &s, int &k) {

    int cnt = 0;
    int z = 0;
    int o = 0;
    int lnds = 0;
    int n = (int)s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            z++;
            lnds = max({lnds, z});
        } else {
            lnds = max({
                lnds,
                one,
            })
        }
    }

    return cnt >= k;
}
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n == k) {
        cout << "1\n";
        return;
    }
    int l = 0;
    int r = n + 10;
    int ans = 0;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (check(m, s, k)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans << "\n";
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