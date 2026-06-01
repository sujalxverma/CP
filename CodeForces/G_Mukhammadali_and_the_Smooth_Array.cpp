#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n), c(n);
        long long total = 0;
        for (auto &x : a) {
            cin >> x;
        }
        for (auto &x : c) {
            cin >> x;
            total += x;
        }
        /*
        Cost = Total - SUMMATION(elements that we keep in non-dec seq)
        So we need to minimise Cost, thus increase SUMMATION
        So, for each dp[i] , we can store maxvalue of cost that can be made
        for non-dec seq ending at index a[i] as last element.
        */
        vector<long long> dp(n, 0);
        dp[0] = c[0];
        for (long long i = 1; i < n; i++) {
            dp[i] = c[i];
            for (long long j = 0; j < i; j++) {
                if (a[j] <= a[i]) {
                    dp[i] = max(dp[i], dp[j] + c[i]);
                }
            }
        }
        cout << total - *max_element(begin(dp), end(dp)) << "\n";
    }

    return 0;
}