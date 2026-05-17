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
        vector<int> a(n), b(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        int mini = 0;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            if (mini <= maxi) {
                if (a[i] >= b[i]) {
                    if ((mini) + a[i] >= mini) {
                        mini += a[i];
                    } else {
                        maxi += a[i];
                    }
                } else {
                    if (mini + b[i] >= mini) {
                        mini += b[i];
                    } else {
                        maxi += b[i];
                    }
                }
            } else {
                if (a[i] >= b[i]) {
                    if ((maxi) + a[i] >= maxi) {
                        maxi += a[i];
                    } else {
                        mini += a[i];
                    }
                } else {
                    if (maxi + b[i] >= maxi) {
                        maxi += b[i];
                    } else {
                        mini += b[i];
                    }
                }
            }

            // if (maxi < mini) {
            //     swap(maxi, mini);
            // }
        }

        cout << min(mini, maxi) << endl;
    }

    return 0;
}