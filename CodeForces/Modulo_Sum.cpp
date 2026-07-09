#include "bits/stdc++.h"
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n > m) {

        vector<int> f(m + 1, 0);
        vector<int> p(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            p[i] = (p[i - 1] + a[i]) % m;
            f[p[i]]++;
        }

        for (int i = 0; i <= m; i++) {
            if (p)
        }
    }
    return 0;
}