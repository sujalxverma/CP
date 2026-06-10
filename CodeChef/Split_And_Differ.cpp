#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1] && a[i] <= 2) {
            cout << "-1\n";
            return;
        }
    }
    vector<int> ans;
    ans.push_back(a[0]);
    a.push_back(-1);
    for (int i = 1; i < n; i++) {
        if (ans.back() != a[i]) {
            ans.push_back(a[i]);
        } else {
            if (a[i] % 2 == 0) {
                int x = a[i] / 2 - 1;
                int y = a[i] - x;
                if (x == a[i + 1]) {
                    ans.push_back(x);
                    ans.push_back(y);
                } else {
                    ans.push_back(y);
                    ans.push_back(x);
                }
            } else {
                int x = a[i] / 2;
                int y = a[i] - x;
                if (x == a[i + 1]) {
                    ans.push_back(x);
                    ans.push_back(y);
                } else {
                    ans.push_back(y);
                    ans.push_back(x);
                }
            }
        }
    }
    cout << (int)ans.size() << "\n";
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}