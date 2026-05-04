#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
const long long mod = 1e9 + 7;
/*
1. dp[len][num] -> stores how many ways does the sequence can form, with length->len and ending number->num.
2. initially dp[1][num] = 1, cause if length is 1, then that number is present alone in seq.
3. then we traverse with len : 2 -> k.
4. for every number (say A), we find all its factors, and if B is factor of A, then dp[len][A] += dp[len-1][B].
5. At end we store count for all dp[k][number], means length is len, and seq ends with this->number.
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    long long n, k;
    cin >> n >> k;

    vector<vector<long long>> dp(k + 1, vector<long long>(2001, 0));
    for (long long i = 1; i <= 2000; i++) {
        dp[1][i] = 1;
    }

    for (int len = 2; len <= k; len++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (i % j == 0) {
                    dp[len][i] += dp[len - 1][j] % mod;
                    if (i / j != j) {
                        dp[len][i] += dp[len - 1][i / j] % mod;
                    }
                }
            }
        }
    }
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt = (cnt + dp[k][i]) % mod;
    }
    cout << cnt << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}