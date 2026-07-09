#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod = 998244353;
const int MAXN = 2e5;
vector<int> f;
vector<int> fact() {
    vector<int> f(MAXN + 10);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= MAXN + 4; i++) {
        f[i] = (f[i - 1] % mod * i % mod) % mod;
    }
    return f;
}

void solve2() {
    string s;
    cin >> s;
    vector<int> one, zero;
    int n = (int)s.length();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cnt++;
        } else {
            if (cnt > 0) {
                zero.push_back(cnt);
            }
            cnt = 0;
        }
    }
    if (cnt > 0) {
        zero.push_back(cnt);
    }
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt++;
        } else {
            if (cnt > 0) {
                one.push_back(cnt);
            }
            cnt = 0;
        }
    }
    if (cnt > 0) {
        one.push_back(cnt);
    }

    int waystoSelect = 0;
    for (int &x : one) {
        waystoSelect++;
    }
    for (int &x : zero) {
        waystoSelect++;
    }

    cout << n - waystoSelect << " " << f[n - waystoSelect] << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    f = fact();
    while (t--) {
        solve2();
    }

    return 0;
}