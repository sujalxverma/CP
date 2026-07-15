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
        string s;
        cin >> s;
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '#') {
                cnt++;
            } else {
                ans = max(ans, (cnt + 1) / 2);
                cnt = 0;
            }
        }
        ans = max(ans, (cnt + 1) / 2);
        cout << ans << "\n";
    }

    return 0;
}