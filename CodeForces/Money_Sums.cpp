#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<int> dp(sum + 10, 0);
    dp[0] = 1;
    set<int> s;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = sum; j >= a[i]; j--) {
            dp[j] = dp[j] || dp[j - a[i]];
            if (dp[j] == 1) {
                s.insert(j);
            }
        }
    }
    cout << (int)s.size() << "\n";
    for (auto &x : s) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}