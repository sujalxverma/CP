#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<pair<int, int>> b(m);
    for (auto &X : a)
        cin >> X;
    for (int i = 0; i < m; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }

    sort(begin(a), end(a));
    sort(begin(b), end(b));

    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        int val = b[i].first;
        int idx = upper_bound(begin(a), end(a), val) - begin(a);
        ans[b[i].second] = idx;
    }
    for (auto &x : ans) {
        cout << x << " ";
    }

    return 0;
}