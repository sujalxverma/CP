#include "bits/stdc++.h"
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(begin(a), end(a));
    a.erase(unique(begin(a), end(a)), end(a));
    int m = (int)a.size();
    int M = *max_element(begin(a), end(a));
    vector<int> dp(M + 1, 0);
    dp[0] = 0;
    if (a[0] == 1) {
        dp[1] = mp[1];
    } else {
        dp[1] = 0;
    }
    for (int i = 2; i <= M; i++) {
        dp[i] = max(dp[i - 1], i * mp[i] + dp[i - 2]);
    }
    cout << dp[M] << "\n";
    return 0;
}