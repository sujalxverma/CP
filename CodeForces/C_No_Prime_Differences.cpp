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
        vector<vector<int>> g(n + 1, vector<int>(m + 1));
        if (m % 2 == 0) {
            int cnt = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    // g[i][j] = cnt;
                    cout << cnt << " ";
                    cnt++;
                }
                cout << "\n";
            }
        } else if (n % 2 == 0) {
            int cnt = 1;
            for (int j = 1; j <= n; j++) {
                for (int i = 1; i <= m; i++) {
                    // g[i][j] = cnt;
                    cout << cnt << " ";
                    cnt++;
                }
                cout << "\n";
            }
        } else {
            int cnt = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    g[i][j] = cnt;
                    cnt++;
                }
            }
            vector<vector<int>> k(n + 1, vector<int>(m + 1));
            int limit = n / 2;

            for (int i = 2; i <= n && limit > 0; i += 2) {
                for (int j = 1; j <= m; j++) {
                    k[i][j] = g[]
                }
            }
        }
    }

    return 0;
}

/*

*/