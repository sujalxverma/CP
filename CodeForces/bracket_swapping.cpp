#include "bits/stdc++.h"
using namespace std;

int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int f = 1;
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int pa = 0;
        int pb = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                if (a[i] == '(') {
                    pa++;
                    pb++;
                } else {
                    pa--;
                    pb--;
                }
            } else {
                if (pa < pb) {
                    pa++;
                    pb--;
                } else {
                    pa--;
                    pb++;
                }
            }

            if (pa < 0 || pb < 0) {
                f = false;
            }
        }

        if (!f) {
            cout << "NO\n";
            continue;
        }

        if (pa == pb && pa == 0) {
            cout << "YES\n";

        } else {
            cout << "NO\n";
        }
    }

    return 0;
}