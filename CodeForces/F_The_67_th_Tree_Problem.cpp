#include "bits/stdc++.h"
#include <numeric>
#define endl '\n'
#define fi first
#define se second
#define pb push_back

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

void solve() {
    ll x, y, i, lol, bambam;
    cin >> x >> y;
    vector<bool> jes(x + y, false);
    vector<ll> a(x + y);
    if (x > y) {
        cout << "NO" << endl;
        return;
    }
    if ((x == y)) {
        if ((x + y) % 2 == 1) {
            cout << "NO" << endl;
            return;
        }
    }
    if ((x == 0) && ((x + y) % 2) == 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    ll br = (x + y + 1) / 2;
    lol = 0;
    bambam = 1;
    for (i = 1; i < x + y; i++) {
        if (br < y) {
            if (lol) {
                lol = 0;
                jes[i] = true;
                br++;
            } else {
                jes[i] = true;
                lol = 1;
            }
        } else {
            bambam = i + 1;
            break;
        }
    }
    for (i = 1; i < x + y; i++) {
        if (jes[i]) {
            cout << bambam << " " << i + 1 << endl;
        } else {
            cout << i + 1 << " " << 1 + (i + 1) % (x + y) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
