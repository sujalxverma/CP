#include "bits/stdc++.h"
using namespace std;
int bit_ceil(int x) {
    if (x <= 1)
        return 1;
    return 1 << (32 - __builtin_clz(x - 1));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int N = n;
    if (n == 1) {
        cout << "1 0\n";
        return 0;
    }
    vector<int> f(1e6 + 10, 0);
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                f[i]++;
                n = n / i;
            }
        }
    }
    if (n > 1) {
        f[n]++;
    }
    int value = 1;
    int mx = 0;

    for (int i = 2; i <= 1e6; i++) {
        if (f[i] > 0) {
            value *= i;
            mx = max(mx, f[i]);
        }
    }

    int target = bit_ceil(mx);

    bool allEqual = true;
    for (int i = 2; i <= 1e6; i++) {
        if (f[i] > 0 && f[i] != target) {
            allEqual = false;
        }
    }

    int ops = (int)log2(target);

    if (!allEqual)
        ops++;

    cout << value << " " << ops << "\n";

    return 0;
}