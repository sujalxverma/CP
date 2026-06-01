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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> b;
        b.push_back(a[0]);
        for (int i = 1; i < n; i++) {
            if (b.back() != a[i]) {
                b.push_back(a[i]);
            }
        }
        vector<int> dp((int)b.size(), 1);
        for (int i = 1; i < (int)b.size(); i++) {
            {
                if (b[i - 1] + 1 < b[i]) {
                    dp[i] = dp[i - 1] + 1;
                } else {
                    if (i - 2 >= 0) {
                        dp[i] = dp[i - 2] + 1;
                    }
                }
            }
        }
        cout << *max_element(begin(dp), end(dp)) << "\n";
    }

    return 0;
}