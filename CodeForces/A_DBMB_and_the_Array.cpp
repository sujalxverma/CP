#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, s, x;
        cin >> n >> s >> x;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int l;
            cin >> l;
            sum += l;
        }

        if (sum == s) {
            cout << "YES\n";
        } else if (s > sum && (s - sum) % x == 0) {  // added s > sum
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
