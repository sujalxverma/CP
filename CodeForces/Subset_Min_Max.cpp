#include "bits/stdc++.h"
using namespace std;

int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string s;
        cin >> s;
        int m = (int)s.length();

        int ans = 1;
        vector<pair<int, char>> p;
        for (int i = 0; i < n; i++) {
            p[i].first = a[i];
            p[i].second = s[i];
        }
        sort(begin(p), end(p));
        for (int i = 0; i < n; i++) {
            if (p[i].second == '1') {
                ans *= p[i].first;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (p[i].second == '1') {
                ans *= p[i].first;
                break;
            }
        }

        // initial answer is ans.
        if (p[n - 1].second)
    }

    return 0;
}