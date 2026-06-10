#include "bits/stdc++.h"
using namespace std;
vector<int> cnt;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    multiset<int> s(begin(a), end(a));
    int maxi = *max_element(begin(a), end(a));
    int l = 0;
    int r = maxi + 2;
    int ans = 0;
    while (l <= r) {
        int m = l + (r - l) / 2;
        vector<int> rem;
        bool f = true;
        for (int k = m - 1; k >= 0; k--) {
            auto it = s.lower_bound(k);
            if (it != s.end() && *it == k) {
                rem.push_back(*it);
                s.erase(it);
                continue;
            }
            it = s.lower_bound(2 * k + 1);
            if (it != s.end() && *it >= 2 * k + 1) {
                rem.push_back(*it);
                s.erase(it);
                continue;
            }
            f = false;
            break;
        }
        for (auto &x : rem) {
            s.insert(x);
        }
        if (f) {
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