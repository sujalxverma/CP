#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n;
    cin >> n;
    int k, l, r;
    cin >> k >> l >> r;
    vector<int> a(n);
    vector<int> f(2e5 + 10, 0);
    int i = 0;
    int j = 0;
    int cnt = 0;
    int ans = 0;
    if (k > r) {
        cout << "0\n";
        return;
    }
    while (i < n && j < n) {
        f[a[i]]++;
        if (a[i] == 1) {
            cnt++; // caught first time.
        }
        if (cnt == k) {

            if (i - j + 1 >= l && i - j + 1 <= r) {
                ans++;
            } else {
                f[a[j]]--;
                if (f[a[j]] == 0) {
                    // distinct values decreases.
                } else {
                    ans++;
                }
                j++;
            }
        }
    }
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