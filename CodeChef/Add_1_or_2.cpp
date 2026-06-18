#include "bits/stdc++.h"
using namespace std;
#define int long long

int f(vector<pair<int, int>> a, int m) {
    // send -> (ai + bi) - m
    // recieve -> (m - ai - bi)/2
    // send > recieve -> false , else true;

    int n = (int)a.size();

    int recv = 0;
    int send = 0;
    for (auto &[x, y] : a) {
        if (x + y > m) {
            send += (x + y) - m;
        } else {
            recv += (m - x - y) / 2;
        }
    }

    if (send <= recv) {
        return 1;
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        int maxA = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            maxA = max(maxA, a[i].first);
        }
        int maxB = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i].second;
            maxB = max(maxB, a[i].second);
        }
        sort(begin(a), end(a));
        int s = maxA;
        int ans = 0;
        int e = maxA + maxB;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (f(a, m)) {
                ans = m;
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}