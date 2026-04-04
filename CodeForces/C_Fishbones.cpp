#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> vectorA(n), vectorB(n);
    for (int i = 0; i < n; i++) {
        cin >> vectorA[i] >> vectorB[i];
        vectorB[i]--;
    }

    int m;
    cin >> m;

    vector<string> stringS(m);
    for (int i = 0; i < m; i++) {
        cin >> stringS[i];
    }

    bool exists[11][11][26] = {};

    for (auto &s : stringS) {
        int len = s.size();
        for (int i = 0; i < len; i++) {
            exists[len][i][s[i] - 'a'] = true;
        }
    }

    for (auto &s : stringS) {
        if ((int)s.size() != n) {
            cout << "No\n";
            continue;
        }

        bool ok = true;
        for (int i = 0; i < n; i++) {
            int len = vectorA[i];
            int pos = vectorB[i];
            char c = s[i];

            if (!exists[len][pos][c - 'a']) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }

    return 0;
}