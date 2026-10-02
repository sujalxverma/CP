#include "bits/stdc++.h"
using namespace std;
#define int long long

int f(unordered_map<int, int> &mp, int &q, int &mx, int &sum) {

    // intitally we only want 1 copy of mp+x, thus q = 1
    int extra = 0;
    for (int i = mx; i >= 1; i--) {
        if (q > sum) {
            return 0;
        }
        if (!mp.count(i)) {
            q = 2 * q;
        } else {

            extra += max(0LL, mp[i] - q);
            q += max(0LL, q - mp[i]);
        }
    }
    if (mp[0] + extra >= q) {
        return 1;
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // vector<array<int, 2>> a;
        int ans = -1;
        int sum = 0;
        int maxi = -1;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            sum += v;
            mp[u] += v;
            ans = max(ans, u);
            maxi = max(maxi, u);
        }
        int s = 1;
        int e = 33;
        while (s <= e) {
            int m = s + (e - s) / 2;
            int q = 1;
            int mx = maxi + m - 1;
            if (f(mp, q, mx, sum)) {
                s = m + 1;
                ans = maxi + m;
            } else {
                e = m - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
