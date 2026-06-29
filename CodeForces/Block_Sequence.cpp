#include "bits/stdc++.h"
using namespace std;
const int inf = 1e9;
int n;
vector<int> a;
vector<int> dp;
/*
Either skip this num, means this num will be deleted from seq.
Or choose this as length of subarray, and move to new location.
Return min(choose,skip)
*/
int f(int idx) {
    if (idx == n) {
        return 0;
    }
    if (idx > n) {
        return inf;
    }
    if (dp[idx] != -1) {
        return dp[idx];
    }
    return dp[idx] = min(1 + f(idx + 1), f(idx + a[idx] + 1));
}
void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    /*
    dp.assign(n, -1);
    cout << f(0) << "\n";
    */
    // ITERATIVE DP
    dp.assign(n + 2, inf);
    dp[n - 1] = 1;
    dp[n] = 0;
    for (int i = n - 2; i >= 0; i--) {
        dp[i] = min(1 + dp[i + 1], dp[i]);
        if (i + a[i] + 1 <= n) {
            dp[i] = min(dp[i], dp[i + a[i] + 1]);
        }
    }
    cout << dp[0] << "\n";
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