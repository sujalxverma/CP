#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll a, b, c, m;
        cin >> a >> b >> c >> m;

        ll ab = lcm(a, b);
        ll bc = lcm(b, c);
        ll ac = lcm(a, c);
        ll abc = lcm(a, lcm(b, c));

        ll A_all = m / a;
        ll B_all = m / b;
        ll C_all = m / c;

        ll AB_all = m / ab;
        ll BC_all = m / bc;
        ll AC_all = m / ac;

        ll ABC = m / abc;

        // Alice
        ll onlyA = A_all - AB_all - AC_all + ABC;
        ll AB_only = AB_all - ABC;
        ll AC_only = AC_all - ABC;
        ll Alice = 6 * onlyA + 3 * AB_only + 3 * AC_only + 2 * ABC;

        // Bob
        ll onlyB = B_all - AB_all - BC_all + ABC;
        ll BA_only = AB_only; // same as AB_only
        ll BC_only = BC_all - ABC;
        ll Bob = 6 * onlyB + 3 * BA_only + 3 * BC_only + 2 * ABC;

        // Carol
        ll onlyC = C_all - AC_all - BC_all + ABC;
        ll CA_only = AC_only;
        ll CB_only = BC_only;
        ll Carol = 6 * onlyC + 3 * CA_only + 3 * CB_only + 2 * ABC;

        cout << Alice << " " << Bob << " " << Carol << "\n";
    }

    return 0;
}