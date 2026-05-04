#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
string s;
vector<vector<int>> dp;
const int mod = 998244353;
int f(int idx, char prev) {
    if (idx == 0) {
        if ((s[idx] - 'a') != prev) {
            return 1;
        } else {
            return 0;
        }
    }
    if (idx < 0) {
        return 0;
    }

    if (dp[idx][prev] != -1)
        return dp[idx][prev] % mod;

    int nottake = 0 + f(idx - 1, prev);
    int take = 0;
    if ((s[idx] - 'a') != prev) {
        take = 1 + f(idx - 1, (s[idx] - 'a'));
    }

    return dp[idx][prev] = (take + nottake) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    cin >> s;
    dp.resize((int)s.length(), vector<int>(4, -1));
    int ans = f((int)s.length() - 1, 3);
    cout << ans % mod << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}