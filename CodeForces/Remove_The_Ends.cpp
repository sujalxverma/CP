#include "bits/stdc++.h"
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int sum = 0;
        // maximise sum, if a[i] < 0, choose prefix : [0,i-1], else suffix : [i+1,n-1]
        vector<int> p(n + 1, 0), s(n + 1, 0);
        p[0] = (a[0] > 0 ? a[0] : 0);
        s[n - 1] = (a[n - 1] < 0 ? -a[n - 1] : 0);

        for (int i = 1; i < n; i++) {
            p[i] = p[i - 1];
            if (a[i] > 0) {
                p[i] += a[i];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            s[i] = s[i + 1];
            if (a[i] < 0) {
                s[i] += -a[i];
            }
        }
        for (int i = 0; i < n; i++) {
            sum = max(sum, p[i] + s[i]);
        }
        cout << sum << "\n";
    }
    return 0;
}