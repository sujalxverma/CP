#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int m, d, a, b;
int dp[11][2005][2];
int lena, lenb;
vector<int> nums;
// dp[pos][sum][tight]
// f() will work for a and b.
int f(int pos, int sum, int tight, int len) {
    if (pos == len)
        return sum == 0;
    if (dp[pos][sum][tight] != -1) {
        return dp[pos][sum][tight];
    }

    int res = 0;
    if (pos == 0) {
        for (int i = 1; i <= 9; i++) {
            if (i == d) {
                continue;
            }
            if (nums[pos] > i) {
                res = (res % mod + f(pos + 1, (sum * 10 + i) % m, 0, len) % mod) % mod;
            } else if (nums[pos] == i) {
                res = (res % mod + f(pos + 1, (sum * 10 + i) % m, 1, len) % mod) % mod;
            }
        }
    } else {
        if (pos % 2 == 1) {
            // definitely needs to be d.
            if (tight == 0) {
                res = (res % mod + f(pos + 1, (sum * 10 + d) % m, 0, len) % mod) % mod;
            } else {
                if (nums[pos] == d) {
                    res = (res % mod + f(pos + 1, (sum * 10 + d) % m, 1, len) % mod) % mod;
                } else if (nums[pos] > d) {
                    res = (res % mod + f(pos + 1, (sum * 10 + d) % m, 0, len) % mod) % mod;
                }
            }
        } else {
            for (int i = 0; i <= 9; i++) {
                if (i == d) {
                    continue;
                }
                if (nums[pos] > i) {
                    res = (res % mod + f(pos + 1, (sum * 10 + i) % m, 0, len) % mod) % mod;
                } else if (nums[pos] == i) {
                    res = (res % mod + f(pos + 1, (sum * 10 + i) % m, 1, len) % mod) % mod;
                } else if (tight == 0 && nums[pos] < i) {
                    res = (res % mod + f(pos + 1, (sum * 10 + i) % m, 0, len) % mod) % mod;
                } else if (tight == 1 && nums[pos] < i) {
                    // do nothing
                }
            }
        }
    }

    return dp[pos][sum][tight] = res % mod;
}

int f2(int pos, int sum, int len, int tight = 0) {
    if (pos == len)
        return sum == 0;
    if (dp[pos][sum][tight] != -1) {
        return dp[pos][sum][tight];
    }
    int res = 0;
    if (pos == 0) {
        for (int i = 1; i <= 9; i++) {
            if (i == d) {
                continue;
            }
            res = (res % mod + f2(pos + 1, (sum * 10 + i) % m, len, 0) % mod) % mod;
        }
    } else {
        if (pos % 2 == 1) {
            res = (res % mod + f2(pos + 1, (sum * 10 + d) % m, len, 0) % mod) % mod;
        } else {
            for (int i = 0; i <= 9; i++) {
                if (i == d) {
                    continue;
                }
                res = (res % mod + f2(pos + 1, (sum * 10 + i) % m, len, 0) % mod) % mod;
            }
        }
    }

    return dp[pos][sum][tight] = res % mod;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> d >> a >> b;
    b--;
    int cpya = a;
    int cpyb = b;
    while (cpya > 0) {
        lena++;
        cpya /= 10;
    }
    while (cpyb > 0) {
        lenb++;
        cpyb /= 10;
    }
    int ans1 = 0;
    int ans2 = 0;
    cpya = a;
    while (cpya > 0) {
        nums.push_back(cpya % 10);
        cpya /= 10;
    }
    reverse(begin(nums), end(nums));
    memset(dp, -1, sizeof(dp));
    ans1 = (ans1 % mod + f(0, 0, 1, lena) % mod) % mod;
    nums.clear();
    cpyb = b;
    while (cpyb > 0) {
        nums.push_back(cpyb % 10);
        cpyb /= 10;
    }
    reverse(begin(nums), end(nums));
    memset(dp, -1, sizeof(dp));
    ans2 = (ans2 % mod + f(0, 0, 1, lenb) % mod) % mod;

    for (int i = lena - 1; i >= 1; i--) {
        memset(dp, -1, sizeof(dp));
        ans1 = (ans1 % mod + f2(0, 0, i, 1) % mod) % mod;
    }
    for (int i = lenb - 1; i >= 1; i--) {
        memset(dp, -1, sizeof(dp));
        ans2 = (ans2 % mod + f2(0, 0, i, 1) % mod) % mod;
    }

    cout << (ans1 - ans2 + mod) % mod << '\n';

    return 0;
}