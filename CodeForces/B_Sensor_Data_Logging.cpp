#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> a[i];

    cout << 0 << " " << a[0] << "\n";
    int cur = a[0];

    for (int i = 1; i <= n; i++) {
        if (abs(a[i] - cur) >= k) {
            cout << i << " " << a[i] << "\n";
            cur = a[i];
        }
    }

    return 0;
}