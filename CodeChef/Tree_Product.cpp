#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod = 1'000'000'007;
int X;
int f(vector<int> &a, int idx) {
    if (idx >= X) {
        return 1;
    }
    return a[idx] * max(f(a, 2 * idx + 1), f(a, 2 * idx + 2));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int h;
        cin >> h;
        if (h == 0)
            break;
        X = (1 << h) - 1;
        vector<int> a((1 << h) - 1);
        for (int i = 0; i < (1 << h) - 1; i++) {
            cin >> a[i];
        }
        cout << f(a, 0) % mod << "\n";
    }

    return 0;
}