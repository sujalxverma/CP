#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
long long MAXN;
vector<long long> dp;
vector<long long> f;
long long help(long long idx) {
    if (idx >= MAXN) {
        return 0;
    }

    if (dp[idx] != -1) {
        return dp[idx];
    }

    long long nottake = 0 + help(idx + 1);
    long long take = idx * f[idx] + help(idx + 2);

    return dp[idx] = max(nottake, take);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(begin(v), end(v));
    MAXN = v[n - 1] + 1;
    f.resize(MAXN, 0);
    dp.assign(MAXN + 1, 0);
    for (long long i = 0; i < n; i++) {
        f[v[i]]++;
    }
    // cout << help(1) << "\n";
    dp[MAXN - 1] = f[MAXN - 1] * (MAXN - 1);
    for (int i = MAXN - 2; i >= 1; i--) {
        dp[i] = max(dp[i + 1], f[i] * i + dp[i + 2]);
    }

    cout << dp[1] << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}