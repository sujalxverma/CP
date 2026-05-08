#include "bits/stdc++.h"
using namespace std;

int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, x;
    cin >> n >> x;
    vector<long long> w;
    vector<long long> v;
    vector<long long> w1(n), v1(n), k1(n);
    for (long long i = 0; i < n; i++) {
        cin >> w1[i];
    }
    for (long long i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (long long i = 0; i < n; i++) {
        cin >> k1[i];
    }

    for (long long i = 0; i < n; i++) {
        long long weight = w1[i], value = v1[i], k = k1[i];

        long long power = 1;
        while (power <= k) {
            w.push_back(power * weight);
            v.push_back(power * value);
            k = k - power;
            power *= 2;
        }
        if (k > 0) {
            w.push_back(k * weight);
            v.push_back(k * value);
        }
    }

    n = (long long)v.size();
    vector<long long> dp(x + 1, 0);
    for (long long i = 0; i <= x; i++) {
        if (w[0] <= i) {
            dp[i] = v[0];
        }
    }
    // combinational DP, we traverse index, then cost, why ? cause we will not use this index ever again.
    for (long long i = 1; i < n; i++) {
        for (long long j = x; j >= 0; j--) {

            if (w[i] <= j) {
                dp[j] = max(dp[j], v[i] + dp[j - w[i]]);
            }
        }
    }

    cout << dp[x] << "\n";
    return 0;
}