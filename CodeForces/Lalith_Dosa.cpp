#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> b;
    for (int i = 1; i <= n; i++) {
        if (a[i] > i - 1) {
            b.push_back(a[i] - (i - 1));
        }
    }

    vector<int> dp;
    dp.push_back(b[0]);
    for (int i = 1; i < (int)b.size(); i++) {
        if (b[i] > dp.back()) {
            dp.push_back(b[i]);
        } else {
            auto idx = lower_bound(begin(dp), end(dp), b[i]);
            *idx = b[i];
        }
    }

    cout << n - (int)dp.size() << "\n";
    return 0;
}