#include "bits/stdc++.h"
using namespace std;

int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--) {
        /* code */
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long cnt = 0;
        for (long long i = n - 2; i >= 0; i--) {
            if (a[i] <= 0) {
                if (a[i + 1] + a[i] > 0) {
                    cnt++;
                    a[i] = a[i + 1] + a[i];
                }
            } else {
                if (a[i] + a[i + 1] >= a[i]) {
                    a[i] += a[i + 1];
                }
                cnt++;
            }
        }
        if (a[n - 1] > 0)
            cnt++;

        cout << cnt << "\n";
    }

    return 0;
}