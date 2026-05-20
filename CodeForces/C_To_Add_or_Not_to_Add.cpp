#include "bits/stdc++.h"
using namespace std;
int n, k;
pair<int, int> f(vector<int> a, int m) {
    int op = k;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int diff = max(0, m - a[i]);
        if (op >= diff) {
            a[i] = m;
            op -= diff;
            mp[a[i]]++;
        } else {
            mp[a[i]]++;
        }
    }
    int v = 0;
    int c = 0;
    for (auto &[x, y] : mp) {
        if (y > c) {
            c = y;
            v = x;
        }
    }
    if (mp.count(m)) {
        if (mp[v] == mp[m]) {
        }
    }
    if (v == m) {
        return {v, c};
    }
    return {-1, -1};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int s = 0;
    int e = 1e9;
    int ans = 0;
    int fr = 0;
    sort(begin(a), end(a));
    while (s <= e) {
        int m = s + (e - s) / 2;
        auto [d, b] = f(a, m);
        if (d == -1) {
            s = m + 1;
        } else {
            ans = d;
            fr = b;
        }
    }
    cout << ans << " " << fr << "\n";
    return 0;
}