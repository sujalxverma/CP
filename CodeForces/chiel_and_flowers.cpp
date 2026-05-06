#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long r, g, b;
    cin >> r >> g >> b;
    if (r >= g) {
        swap(r, g);
    }
    if (r >= b) {
        swap(r, b);
    }
    // r will have least value.
    if (r == g && g == b) {
        cout << r << "\n";
        return 0;
    }
    ll ans = 0;
    for (ll i : {0, 1, 2}) {
        if (i > r)
            continue;
        ans = max(ans, i + (r - i) / 3 + (b - i) / 3 + (g - i) / 3);
    }
    cout << ans << "\n";

    return 0;
}