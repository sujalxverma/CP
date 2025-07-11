#include <iostream>
using namespace std;

using ll = long long;

void solve() {
    ll a, b;
    cin >> a >> b;

    if (b == 1) {
        cout << "NO" << endl;
        return;
    }

    // Output: a, a*b, a*(b+1)
    // Explanation:
    // - a
    // - a*b
    // - a*(b + 1) = a*b + a
    // All three values are distinct and follow a simple pattern.
    cout << "YES" << endl;
    cout << a << " " << a * b << " " << a * (b + 1) << endl;
    // i never thought about changing b in RHS, and also what if b==1.
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
