#include "bits/stdc++.h"
using namespace std;
#define long long
vector<int> f() {
    int N = 300;
    vector<int> primes(N + 1, 0);
    primes[0] = primes[1] = 1;
    for (int i = 2; i * i <= N; i++) {
        if (primes[i] == 1)
            continue;
        for (int j = i * i; j <= N; j += i) {
            primes[j] = 1;
        }
    }
    vector<int> k;
    for (int i = 0; i <= N; i++) {
        if (primes[i] == 0) {
            k.push_back(i);
        }
    }
    return k;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n <= 2) {
        cout << "-1\n";
        return 0;
    }
    vector<int> p = f();
    vector<int> ans(n);
    ans[0] = 3 * 7;
    ans[n - 1] = 5 * 7;
    for (int i = 1; i < n - 1; i++) {
        ans[i] = 3 * 5;
    }
    int j = 5;
    for (int i = 0; i < n; i++) {
        ans[i] *= p[j];
        j++;
    }
    int g = 0;
    for (auto &x : ans) {
        cout << x << "\n";
        g = gcd(g, x);
    }
    // cout << g << "\n";
    return 0;
}