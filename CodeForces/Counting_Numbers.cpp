#include "bits/stdc++.h"
using namespace std;
int a, b;

vector<vector<vector<int>>> dp;
vector<int> toVector(long long n) {
    if (n == 0)
        return {0};

    vector<int> v;
    while (n) {
        v.push_back(n % 10);
        n /= 10;
    }
    reverse(v.begin(), v.end());
    return v;
}
int f(vector<int> num, int idx, int prev, int s, int n) {
    if (idx >= n) {
        return 1; // surpassed length of number.
    }

    int ans = 0;

    if (s == 0) {
        // number is not smaller.
        for (int i = 0; i <= num[idx]; i++) {
            if (i < num[idx] && i != prev) {
                ans += f(num, idx + 1, i, 1, n);
            } else if (i == num[idx] && i != prev) {
                ans += f(num, idx + 1, i, 0, n);
            }
        }

    } else {
        // number is smaller.
        for (int i = 0; i <= 9; i++) {
            if (i != prev) {
                ans += f(num, idx + 1, i, 1, n);
            } else if (i != prev) {
                ans += f(num, idx + 1, i, 0, n);
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;

    // dp.resize(n, vector<vector<int>>(11, vector<int>(2, -1)));
    // dp[i][j][k] = numbers formed, when current length is (i+1) and prev chosen digit is j,
    //               k means, if sq[i] < num[i], then 1, else 0.
    vector<int> nums1 = toVector(a - 1);
    vector<int> nums2 = toVector(b);
    cout << f(nums2, 0, 11, 0, (int)nums2.size()) - f(nums1, 0, 11, 0, (int)nums1.size()) << "\n";

    return 0;
}