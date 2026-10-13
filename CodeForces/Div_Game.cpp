#include "bits/stdc++.h"
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> sums(10000, 0);
    sums[1] = 1;
    for (int i = 2; i < 10000; i++) {
        sums[i] = sums[i - 1] + i;
    }
    int cpy = n;
    map<int, int> mp;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                mp[i]++;
                n = n / i;
            }
        }
    }
    if (n > 1) {
        mp[n]++;
    }
    int ans = 0;
    int lg = floor(log2(cpy));
    // cout << mp.size();
    if (mp.empty()) {
        cout << 1 << "\n"; // n is prime
    } else {
        for (auto [x, y] : mp) {
            for (int i = 1; i <= lg; i++) {
                if (sums[i] <= y)
            }
        }
        cout << ans << "\n";
    }
    return 0;
}