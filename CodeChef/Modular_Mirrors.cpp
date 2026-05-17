#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n % 3 != 2) {
            cout << "-1\n";
            continue;
        }

        for (int i = 0; i < n; i++) {
            int r = i % 6;
            if (r < 2) {
                cout << "1 ";
            } else if (r == 2 || r == 5) {
                cout << "0 ";
            } else {
                cout << m - 1 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}