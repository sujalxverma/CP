#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> a(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> a[i];

    vector<ll> need(m + 1, 0);

    for (int i = 0; i < n; i++) {
        int a;
        ll b;
        cin >> a >> b;
        need[a] += b;
    }

    ll ans = 0;

    for (int j = 1; j <= m; j++) {
        ans += min(a[j], need[j]);
    }

    cout << ans << "\n";
}