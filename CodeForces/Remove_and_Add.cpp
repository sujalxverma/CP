#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[a[i]].push_back(i);
        }
        int ans = -1e9;
        for (auto &[x, v] : mp) {
            if (v.size() == 1) {
                continue;
            }
            if (v.size() == 2) {

                ans = max({ans, min(v[1] - v[0], v[v.size() - 1] - v[v.size() - 2])});
            } else {
                ans = max({ans, min(v[1] - v[0] + 1, 1 + v[v.size() - 1] - v[v.size() - 2])});
            }
        }
        cout << (ans == -1e9 ? 0 : ans) << "\n";
    }

    return 0;
}