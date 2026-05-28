#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<ll> p(n, abs(a[0])), s(n + 1, 0);
    s[n - 1] = a[n - 1];

    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] + abs(a[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        s[i] = s[i + 1] + a[i];
    }
    ll best = s[0];
    int idx = -1;

    for (int i = 1; i < n; i++) {
        if (a[i] > 0) {
            ll score = p[i - 1] + s[i + 1] - a[i];
            if (score > best) {
                best = score;
                idx = i;
            }
        }
    }
    if (idx == -1) {
        cout << "0\n\n";
        return;
    }
    vector<int> ans;
    for (int i = idx - 1; i >= 0; i--) {
        if (ans.size() & 1)
            a[i] = -a[i];
        if (a[i] > 0)
            ans.push_back(i);
    }
    ans.push_back(idx);

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
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