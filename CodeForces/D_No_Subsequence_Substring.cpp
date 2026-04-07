#include <iostream>
#include <vector>
using namespace std;
string a, b;
long long n, m;
vector<vector<long long>> dp;
/*
 * Find number of substrings of a such that string b is its subsequence.
 * How ?
 * for each index i, find min r, such that it is a subsequence.
 * then for every r' >= r, this hold true.
 * thus its contribution is (n-r).
 *
 * Precomputation of next occurence.
 * next[i][c] = smalong longest index >= i where character c appears.
 * since only 26 characters, size is n*26
 */

long long f(long long idx1, long long idx2) {
    if (idx2 == m)
        return (n - idx1 + 1);
    if (idx1 == n)
        return 0;

    if (n - idx1 < m - idx2)
        return 0; // pruning

    long long &res = dp[idx1][idx2];
    if (res != -1)
        return res;

    res = f(idx1 + 1, idx2);

    if (a[idx1] == b[idx2]) {
        res += f(idx1 + 1, idx2 + 1);
    }

    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;

    n = a.length();
    m = b.length();

    dp.assign(n, vector<long long>(m, -1));

    long long ans = 0;
    for (long long l = 0; l < n; l++) {
        ans += f(l, 0);
    }

    cout << ans << "\n";
}