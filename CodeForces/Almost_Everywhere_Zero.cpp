#include "bits/stdc++.h"
using namespace std;
#define int long long
string s;
int k;
vector<int> nums;
// dp[len-pos][t][prev d][k] : (len - pos) left ,previous chosen digit is d, and number
// of non-zero digits are k, what is in the cache.
int dp[105][2][4];
int ft(int pos, int f, int c, int len) {
    if (len == pos) {
        return (c == k);
    }

    if (pos != 0 && dp[len - pos][f][c] != -1) {
        return dp[len - pos][f][c];
    }

    int ans = 0;
    int start = (pos == 0) ? 1 : 0;

    for (int i = start; i <= 9; i++) {
        if (f == 0) {
            if (i != 0 && c + 1 <= k) {
                ans += ft(pos + 1, 0, c + 1, len);
            } else if (i == 0) {
                ans += ft(pos + 1, 0, c, len);
            }
        } else {
            if (nums[pos] > i && i != 0 && c + 1 <= k) {
                ans += ft(pos + 1, 0, c + 1, len);
            } else if (nums[pos] == i && i != 0 && c + 1 <= k) {
                ans += ft(pos + 1, 1, c + 1, len);
            } else if (i == 0) {
                if (nums[pos] == 0) {
                    ans += ft(pos + 1, 1, c, len);
                } else {
                    ans += ft(pos + 1, 0, c, len);
                }
            }
        }
    }

    if (pos != 0) {
        return dp[len - pos][f][c] = ans;
    }

    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    cin >> s;
    cin >> k;
    for (int i = 0; i < (int)s.length(); i++) {
        nums.push_back(s[i] - '0');
    }

    int ans = 0;
    for (int len = 1; len <= (int)nums.size(); len++) {
        if (len == (int)nums.size()) {
            ans += ft(0, 1, 0, len);
        } else {
            ans += ft(0, 0, 0, len);
        }
    }

    cout << ans << "\n";

    return 0;
}