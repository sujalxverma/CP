#include "bits/stdc++.h"
using namespace std;
// T.C : O(n+q)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> p(n + 3, 1);
    p[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] >= a[i - 1]) {
            p[i] = p[i - 1];
        } else {
            p[i] = i;
        }
    }
    vector<int> s(n + 2, n);
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] >= a[i + 1]) {
            s[i] = s[i + 1];
        } else {
            s[i] = i;
        }
    }
    bool f = false;
    vector<int> peak(n + 2, n);
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] > a[i + 1]) {
            peak[i] = i;
        } else {
            peak[i] = peak[i + 1];
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << "Yes\n";
            continue;
        }
        // check for non-decreasing.
        if (p[l] == p[r]) {
            cout << "Yes\n";
            continue;
        }
        // check for non-increasing.
        if (s[l] == s[r]) {
            cout << "Yes\n";
            continue;
        }
        // check for mountain-peak-variation
        // if, l's forward peak == r's backward peak
        if (s[peak[l]] == s[r]) {
            cout << "Yes\n";
            continue;
        }
        cout << "No\n";
    }
    return 0;
}