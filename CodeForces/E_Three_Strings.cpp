#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
string a, b, c;
vector<vector<int>> dp;
int f(int idx1, int idx2) {
    // For recursive dp, we can initialize dp with -1.
    if (idx1 == (int)a.length() && idx2 == (int)b.length()) {
        return 0;
    }
    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    int takeA = (idx1 == (int)a.length() ? 1e9 : f(idx1 + 1, idx2) + (a[idx1] != c[idx1 + idx2]));
    int takeB = (idx2 == (int)b.length() ? 1e9 : f(idx1, idx2 + 1) + (b[idx2] != c[idx1 + idx2]));
    return dp[idx1][idx2] = min(takeA, takeB);
}
/*
Why this approach is wrong.
Because we work as per condition, but its possible that choosing A or B, at index i, can lead
to minium answer.
Thus at each index try both possiblities.

int f(int idx1, int idx2) {
if (idx1 == (int)a.length() && idx2 == (int)b.length()) {
    return 0;
}
if (idx1 == (int)a.length()) {
    if (b[idx2] == c[idx1 + idx2]) {
        return f(idx1, idx2 + 1);
    } else {
        return 1 + f(idx1, idx2 + 1);
    }
}

if (idx2 == (int)b.length()) {
    if (a[idx1] == c[idx1 + idx2]) {
        return f(idx1 + 1, idx2);
    } else {
        return 1 + f(idx1 + 1, idx2);
    }
}

if (a[idx1] == c[idx1 + idx2] && b[idx2] == c[idx1 + idx2]) {
    return min(f(idx1 + 1, idx2), f(idx1, idx2 + 1));
}
if (a[idx1] == c[idx1 + idx2] && b[idx2] != c[idx1 + idx2]) {
    return f(idx1 + 1, idx2);
}
if (a[idx1] != c[idx1 + idx2] && b[idx2] == c[idx1 + idx2]) {
    return f(idx1, idx2 + 1);
}

return 1 + min(f(idx1 + 1, idx2), f(idx1, idx2 + 1));
}
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto start = high_resolution_clock::now();
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        dp.assign((int)a.length() + 1, vector<int>((int)b.length() + 1, 0));
        // cout << f(0, 0) << "\n"; For recursive dp, initialize dp with -1.
        for (int i = 1; i <= (int)a.length(); i++) {
            dp[i][0] = dp[i - 1][0] + (a[i - 1] != c[i - 1]);
        }
        for (int i = 1; i <= (int)b.length(); i++) {
            dp[0][i] = dp[0][i - 1] + (b[i - 1] != c[i - 1]);
        }

        for (int i = 1; i <= (int)a.length(); i++) {
            for (int j = 1; j <= (int)b.length(); j++) {
                dp[i][j] = min(dp[i - 1][j] + (a[i - 1] != c[i + j - 1]), dp[i][j - 1] + (b[j - 1] != c[i + j - 1]));
            }
        }
        cout << dp[(int)a.length()][(int)b.length()] << "\n";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";
    return 0;
}