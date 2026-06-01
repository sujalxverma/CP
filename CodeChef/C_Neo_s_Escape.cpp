#include "bits/stdc++.h"
using namespace std;
// void p(vector<vector<int>> &g) {
//     for (int i = 0; i < (int)g.size(); i++) {
//         cout << i << " -> ";
//         for (auto &y : g[i]) {
//             cout << y << " ";
//         }
//         cout << "\n";
//     }
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[0] = 0;
        vector<int> b = a;

        vector<int> c = {a[0]};

        // 1. Build the compressed array first
        for (int i = 1; i <= n; i++) {
            if (c.back() != b[i]) { // Read from 'b' (the original copy) or 'a' BEFORE you overwrite it
                c.push_back(b[i]);
            }
        }

        // 2. NOW replace 'a' with 'c'
        a = c;

        // 3. Update 'n' to reflect the newly compressed size
        n = a.size() - 1;
        for (int i = 1; i <= n; i++) {
            if (c.back() != a[i]) {
                c.push_back(a[i]);
            }
        }
        // a.resize(n + 2);
        // a[n + 1] = -1;
        // index compression
        unordered_map<int, int> mp;
        sort(begin(b), end(b));
        b.erase(unique(begin(b) + 1, end(b)), end(b));
        for (int i = 0; i < (int)b.size(); i++) {
            mp[b[i]] = i;
        }

        // graph created
        vector<vector<int>> g((int)b.size() + 2);
        for (int i = 0; i <= n; i++) {
            g[mp[a[i]]].push_back(i);
        }

        int ans = 0;
        vector<int> k(n + 3, -1); // -1 : no clone present.
        for (int i = 0; i < (int)g[mp[b.back()]].size(); i++) {
            int c = g[mp[b.back()]][i];
            int l = g[mp[b.back()]][i] - 1;
            int r = g[mp[b.back()]][i] + 1;
            // l , c , r
            if (l >= 0 && a[l] >= a[c] && k[l] != -1) {
                //
                k[c] = k[l];
            } else if (r <= n && a[r] >= a[c] && k[r] != -1) {
                //
                k[c] = k[r];

            } else {
                ans++;
                k[c] = ans;
            }
        }
        for (int i = (int)b.size() - 2; i >= 1; i--) {

            for (int j = 0; j < g[mp[b[i]]].size(); j++) {
                int c = g[mp[b[i]]][j];
                int l = g[mp[b[i]]][j] - 1;
                int r = g[mp[b[i]]][j] + 1;
                // l , c , r
                if (l >= 0 && a[l] >= a[c] && k[l] != -1) {
                    //
                    k[c] = k[l];
                } else if (r <= n && a[r] >= a[c] && k[r] != -1) {
                    //
                    k[c] = k[r];

                } else {
                    ans++;
                    k[c] = ans;
                }
            }
        }
        // cout << b.back();
        cout << ans << "\n";
    }

    return 0;
}