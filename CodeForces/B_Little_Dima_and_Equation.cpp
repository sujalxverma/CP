#include "bits/stdc++.h"
using namespace std;
using ll = long long;
/*
 * Many numbers may have same sum, but digit orientation is unqiue.
 * Eg 103, and 310 have same digit sum, but when we put their sum in the formula.
 * Then value we get is unique orientation that may correspond to only to one number.
 * Thus sum ranges from 1 to 81, for each sum we will find the corresponding number.
 * And if that number < 1e9, then Yes, else skip it.
 */
ll sum(ll num) {
    ll s = 0;
    while (num > 0) {
        s += (num % 10);
        num /= 10;
    }
    return s;
}
ll binaryExpo(ll n, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1)
            res = (res * n);
        n = (n * n);
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, c;
    cin >> a >> b >> c;
    vector<ll> ans;
    // x = b·s(x)^a + c
    for (ll i = 1; i <= 81; i++) {
        ll num = (b * (binaryExpo(i, a)) + c);
        if (num > 1e9 - 1)
            continue;
        if (i == sum(b * (binaryExpo(i, a)) + c)) {
            ans.push_back(b * (binaryExpo(i, a)) + c);
        }
    }
    cout << (int)ans.size() << "\n";
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}