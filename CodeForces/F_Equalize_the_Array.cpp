#include "bits/stdc++.h"
using namespace std;
vector<int> v;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        v.resize(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            mp[v[i]]++;
        }
        unordered_map<int, int> f;
        for (auto &[x, y] : mp) {
            f[y]++;
        }
        int ans = 1e9;
        for (auto &[x, y] : f) {
            int cnt = 0;
            for (auto &[a, b] : f) {
                if (a == x)
                    continue;
                if (a < x) {
                    cnt += b * a;
                } else {

                    cnt += (b * (a - x));
                }
            }
            // cout << x << " " << cnt << "\n";
            ans = min(cnt, ans);
        }
        cout << ans << "\n";
    }

    return 0;
}