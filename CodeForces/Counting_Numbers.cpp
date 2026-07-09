#include "bits/stdc++.h"
using namespace std;
#define int long long
int dp[19][11][2];
vector<int> nums;

int f(int pos, int d, int t, int len) {
    if (pos == len)
        return 1;
    if (dp[len - pos][d][t] != -1)
        return dp[len - pos][d][t];
    int ans = 0;
    int start = (pos == 0) ? 1 : 0;
    for (int i = start; i <= 9; i++) {
        if (t == 0 && i != d) {
            ans += f(pos + 1, i, 0, len);
        } else {
            if (i < nums[pos] && i != d)
                ans += f(pos + 1, i, 0, len);
            else if (i == nums[pos] && i != d)
                ans += f(pos + 1, i, 1, len);
        }
    }
    return dp[len - pos][d][t] = ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int b, a;
    cin >> b >> a;
    int cpy = a;
    while (cpy > 0) {
        nums.push_back(cpy % 10);
        cpy = cpy / 10;
    }
    reverse(begin(nums), end(nums));
    int ans1 = 0;
    fill(&dp[0][0][0], &dp[0][0][0] + (19 * 11 * 2), -1);
    for (int i = 1; i <= (int)nums.size(); i++) {
        if (i == (int)nums.size()) {
            ans1 += f(0, 10, 1, i);
        } else {
            ans1 += f(0, 10, 0, i);
        }
    }
    if (b == 0) {
        cout << ans1 + 1 << "\n";
        return 0;
    }
    int ans2 = 0;
    nums.clear();
    fill(&dp[0][0][0], &dp[0][0][0] + (19 * 11 * 2), -1);
    cpy = b - 1;
    while (cpy > 0) {
        nums.push_back(cpy % 10);
        cpy = cpy / 10;
    }
    reverse(begin(nums), end(nums));
    for (int i = 1; i <= (int)nums.size(); i++) {
        if (i == (int)nums.size()) {
            ans2 += f(0, 10, 1, i);
        } else {
            ans2 += f(0, 10, 0, i);
        }
    }
    cout << ans1 - ans2 << "\n";
    return 0;
}