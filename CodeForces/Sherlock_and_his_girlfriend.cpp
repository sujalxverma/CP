#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 2, 1);
    int cnt = 1;
    // 1->prime, 2->noprime
    for (int i = 2; i <= n + 1; i++) {
        if (a[i] == 1) {
            for (int j = 2; j * i <= n + 1; j++) {
                a[i * j] = 2;
                cnt++;
            }
        }
    }
    // for (auto &x : a) {
    //     cout << x << " ";
    // }
    cout << (cnt == 1 ? 1 : 2) << "\n";
    for (int i = 2; i <= n + 1; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}