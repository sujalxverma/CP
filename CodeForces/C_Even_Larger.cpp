#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        long long cnt = 0;
        // 2 size subarrays.
        for (int i = 1; i <= n - 1; i++) {
            if (i % 2 == 0) {
                if (a[i] < a[i + 1]) {
                    cnt += a[i + 1] - a[i];
                    a[i + 1] = a[i];
                }
            } else {
                if (a[i + 1] < a[i]) {
                    cnt += a[i] - a[i + 1];
                    a[i] = a[i + 1];
                }
            }
        }

        for (int i = 1; i <= n - 2; i++) {
            if (i % 2 == 0) {
                if (a[i] + a[i + 2] > a[i + 1]) {
                    // do nothing
                } else {
                }
            } else {
                if (a[i] + a[i + 2] <= a[i + 1]) {
                    // do nothing
                } else {
                    long long diff = a[i] + a[i + 2] - a[i + 1];
                    cnt += diff;
                    if (a[i + 2] >= diff) {

                        a[i + 2] -= diff;
                    } else {
                        diff -= a[i + 2];
                        a[i + 2] = 0;
                        a[i] -= diff;
                    }
                }
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}