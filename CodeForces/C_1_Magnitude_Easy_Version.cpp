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
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long maxi = 0;
        long long mini = 0;
        // c -> c+a[i]
        //  c -> abs(c + a[i])
        long long c = 0;
        for (long long i = 0; i < n; i++) {
            long long c1 = maxi;
            long long c2 = mini;
            maxi = max({c1 + a[i], abs(c1 + a[i]), c2 + a[i], abs(c2 + a[i])});
            mini = min({c1 + a[i], abs(c1 + a[i]), c2 + a[i], abs(c2 + a[i])});
            if (maxi < mini) {
                swap(mini, maxi);
            }
        }
        cout << maxi << "\n";
    }

    return 0;
}