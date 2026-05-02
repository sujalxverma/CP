#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
const long long mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    string s;
    cin >> s;
    long long n = (long long)s.length();
    vector<long long> dp(n, 1);
    long long ans = 1;
    long long cnt = 1;
    for (long long i = n - 2; i >= 0; i--) {
        if (s[i] != s[i + 1]) {
            cnt++;
            dp[i] = cnt % mod;
            ans += dp[i] % mod;
        } else {
            dp[i] = 1;
            cnt = 1;
            ans += dp[i] % mod;
        }
    }

    cout << ans % mod << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}