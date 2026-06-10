#include "bits/stdc++.h"
using namespace std;
int n;
vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp;
    dp.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] > dp.back()) {
            dp.push_back(a[i]);
        } else {
            auto it = lower_bound(begin(dp), end(dp), a[i]);
            *it = a[i];
        }
    }
    cout << (int)dp.size() << "\n";
    return 0;
}
