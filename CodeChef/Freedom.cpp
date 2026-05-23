#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long cnt = 0;
        unordered_map<long long, vector<long long>> mp;
        for (long long i = 0; i < n; i++) {
            if (a[i] - 1 == 0)
                continue;
            if ((3 * a[i]) % (a[i] - 1) == 0) {
                mp[(3 * a[i]) / (a[i] - 1)].push_back(i);
            }
        }

        for (long long i = 0; i < n; i++) {
            if (mp.count(a[i])) {
                auto &v = mp[a[i]];
                auto it = upper_bound(v.begin(), v.end(), i);
                cnt += v.end() - it;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}