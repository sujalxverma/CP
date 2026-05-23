#include "bits/stdc++.h"
using namespace std;
using ll = long long;

vector<ll> cost(vector<ll> &f) {
    vector<ll> c((int)f.size());
    for (int i = 0; i < (int)f.size() - 1; i++) {
        if (i == 0) {
            c[i] = 3;
            continue;
        }
        c[i] = f[i + 1] + i * f[i - 1];
    }
    return c;
}

vector<ll> pre() { // will fully calculated during compilation of program.
    vector<ll> a;
    a.push_back(1);
    while (a.back() * 3 <= 1e10) {
        a.push_back(a.back() * 3);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<ll> f = pre();
    vector<ll> c = cost(f);

    while (t--) {
        ll n, k;
        cin >> n >> k;
        if (n <= k) {
            // cout << n << "\n";
            // continue;
        }
        if (k == 1) {
            int it = upper_bound(begin(f), end(f), n) - begin(f) - 1;
            if (it < 0 || f[it] != n) {
                // cout << "-1\n";
            } else {
                // cout << c[it] << "\n";
            }
            // continue;
        }
        cout << n << "\n";
        int idx = upper_bound(begin(f), end(f), n) - begin(f) - 1;
        cout << f[idx] << "\n";
        // for (int i = 0; i < 10; i++) {
        //     cout << f[i] << " " << c[i] << "\n";
        // }
    }

    return 0;
}