#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod = 1'000'000'007;
vector<int> nums;
int d;
string k;
int dp[10002][101][2];
// for pos = 0, do full calculation, do not store in dp.
int f(int pos, int r, int t, int len) {
    if (pos == len) {
        return (r % d == 0);
    }
    if (pos != 0 && dp[len - pos][r][t] != -1) {
        return dp[len - pos][r][t];
    }
    int start = (pos == 0) ? 1 : 0;
    int ans = 0;
    for (int i = start; i <= 9; i++) {
        if (t == 0) {
            ans = (ans % mod + f(pos + 1, (r + i) % d, 0, len) % mod) % mod;
        } else {
            if (nums[pos] > i) {
                ans = (ans % mod + f(pos + 1, (r + i) % d, 0, len) % mod) % mod;
            } else if (nums[pos] == i) {
                ans = (ans % mod + f(pos + 1, (r + i) % d, 1, len) % mod) % mod;
            }
        }
    }
    if (pos != 0) {
        dp[len - pos][r][t] = ans % mod;
    }
    return ans % mod;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k;
    cin >> d;
    fill(&dp[0][0][0], &dp[0][0][0] + (10002 * 101 * 2), -1);
    nums.resize((int)k.length());
    for (int i = 0; i < (int)k.length(); i++) {
        nums[i] = k[i] - '0';
    }
    int ans = 0;
    for (int len = 1; len <= (int)nums.size(); len++) {
        if (len == (int)nums.size()) {
            ans = (ans % mod + f(0, 0, 1, len) % mod) % mod;
        } else {
            ans = (ans % mod + f(0, 0, 0, len) % mod) % mod;
        }
    }
    cout << ans << "\n";
    return 0;
}