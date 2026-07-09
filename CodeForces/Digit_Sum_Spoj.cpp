#include "bits/stdc++.h"
using namespace std;
#define int unsigned long long
int t, a, b;
vector<int> nums;
vector<vector<vector<pair<int, int>>>> dp(18, vector<vector<pair<int, int>>>(11, vector<pair<int, int>>(2, {-1, -1})));

pair<int, int> f(int pos, int digit, int flag, int len) {

    if (pos == len - 1) {
        return dp[1][digit][flag];
    }

    if (dp[len - pos][digit][flag] != pair<int, int>(-1, -1)) {
        return dp[len - pos][digit][flag];
    }
    int start = 0;
    int ways = 0;
    int sum = 0;
    for (int i = start; i <= 9; i++) {
        if (flag == 0) {
            auto res = f(pos + 1, i, 0, len); // at pos+1, we put digit 'i', and if its already computed, then dp already stored it.
            ways += res.first;
            sum += res.second;
        } else {
            if (nums[pos + 1] > i) {
                auto res = f(pos + 1, i, 0, len);
                ways += res.first;
                sum += res.second;
            } else if (nums[pos + 1] == i) {
                auto res = f(pos + 1, i, 1, len);
                ways += res.first;
                sum += res.second;
            }
        }
    }
    int ans = ways * digit + sum;
    return dp[len - pos][digit][flag] = {ways, ans};
}

void solve() {
    nums.clear();
    cin >> a >> b;
    // [0,b] - [0,a]
    dp.assign(18, vector<vector<pair<int, int>>>(11, vector<pair<int, int>>(2, {-1, -1})));
    dp[1][0][1] = dp[1][0][0] = {1, 0};
    dp[1][1][1] = dp[1][1][0] = {1, 1};
    dp[1][2][1] = dp[1][2][0] = {1, 2};
    dp[1][3][1] = dp[1][3][0] = {1, 3};
    dp[1][4][1] = dp[1][4][0] = {1, 4};
    dp[1][5][1] = dp[1][5][0] = {1, 5};
    dp[1][6][1] = dp[1][6][0] = {1, 6};
    dp[1][7][1] = dp[1][7][0] = {1, 7};
    dp[1][8][1] = dp[1][8][0] = {1, 8};
    dp[1][9][1] = dp[1][9][0] = {1, 9};
    int cpy = b;
    while (cpy > 0) {
        nums.push_back(cpy % 10);
        cpy /= 10;
    }
    reverse(begin(nums), end(nums));
    int ans1 = 0;
    for (int len = 1; len <= (int)nums.size(); len++) {
        if (len == (int)nums.size()) {
            for (int i = 1; i <= nums[0]; i++) {
                if (i == nums[0]) {
                    ans1 += f(0, i, 1, len).second;
                } else {
                    ans1 += f(0, i, 0, len).second;
                }
            }
        } else {
            for (int i = 1; i <= 9; i++) {
                ans1 += f(0, i, 0, len).second;
            }
        }
    }
    if (a == 0) {
        cout << ans1 << "\n";
        return;
    }
    nums.clear();
    dp.assign(18, vector<vector<pair<int, int>>>(11, vector<pair<int, int>>(2, {-1, -1})));
    dp[1][0][1] = dp[1][0][0] = {1, 0};
    dp[1][1][1] = dp[1][1][0] = {1, 1};
    dp[1][2][1] = dp[1][2][0] = {1, 2};
    dp[1][3][1] = dp[1][3][0] = {1, 3};
    dp[1][4][1] = dp[1][4][0] = {1, 4};
    dp[1][5][1] = dp[1][5][0] = {1, 5};
    dp[1][6][1] = dp[1][6][0] = {1, 6};
    dp[1][7][1] = dp[1][7][0] = {1, 7};
    dp[1][8][1] = dp[1][8][0] = {1, 8};
    dp[1][9][1] = dp[1][9][0] = {1, 9};
    cpy = a - 1;
    while (cpy > 0) {
        nums.push_back(cpy % 10);
        cpy /= 10;
    }
    reverse(begin(nums), end(nums));
    int ans2 = 0;
    for (int len = 1; len <= (int)nums.size(); len++) {
        if (len == (int)nums.size()) {
            for (int i = 1; i <= nums[0]; i++) {
                if (i == nums[0]) {
                    ans2 += f(0, i, 1, len).second;
                } else {
                    ans2 += f(0, i, 0, len).second;
                }
            }
        } else {
            for (int i = 1; i <= 9; i++) {
                ans2 += f(0, i, 0, len).second;
            }
        }
    }
    cout << ans1 - ans2 << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
