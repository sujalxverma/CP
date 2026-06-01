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
        /*
        101010101 -> max(z,o) -> odd alternating
        10101010 -> -1 -> even alternating
        11111....000000... or 000000....1111... -> 1
        100000.... or 011111... -> 2
        000000....001 or 111...1110 -> 2

        // count number of single 1/0.
        */
        int z = 0;
        int o = 0;
        for (int i = 0; i < n; i++) {
            char ci = s[i];
            char cl = (i == 0 ? s[n - 1] : s[i - 1]);
            char cr = (i == n - 1 ? s[0] : s[i + 1]);
            if (cl != ci && ci != cr) {
                if (ci == '0') {
                    z++;
                } else {
                    o++;
                }
            }
        }

        if (z == o && z == n / 2) {
            // 10101010 -> -1 -> even alternating
            cout << "-1\n";
            continue;
        }
        if (z + o == n - 2 && abs(z - o) == 1) {
            // 101010101 -> max(z,o) -> odd alternating
            cout << max(z, o) << "\n";
            continue;
        }
        if (z == 0 && o == 0) {
            // 11111....000000... or 000000....1111... -> 1
            cout << "1\n";
            continue;
        }
        if (z == 0) {
            cout << o + 1 << "\n";
            continue;
        }
        if (o == 0) {
            cout << z + 1 << "\n";
            continue;
        }
        vector<int> store;
        int l = -1;
        int r = -1;
        bool f = false;
        for (int i = 0; i < n; i++) {
            char ci = s[i];
            char cl = (i == 0 ? s[n - 1] : s[i - 1]);
            char cr = (i == n - 1 ? s[0] : s[i + 1]);
            if (cl != ci && ci != cr && f == false) {

            } else {
            }
        }
    }

    return 0;
}