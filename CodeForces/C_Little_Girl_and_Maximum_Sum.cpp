#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end(), greater<>());
    vector<vector<long long>> s(q);
    vector<long long> diff(n + 4, 0);
    for (long long i = 0; i < q; i++) {
        long long u, v;
        cin >> u >> v;
        s[i].push_back(u);
        s[i].push_back(v);
        diff[u]++;
        diff[v + 1]--;
    }

    vector<vector<long long>> p(n + 1, vector<long long>(2, 0));
    for (long long i = 1; i <= n; i++) {
        p[i][0] = p[i - 1][0] + diff[i];
        p[i][1] = i;
    }
    sort(p.begin() + 1, p.end(), greater<>());
    for (long long i = 1; i <= n; i++) {
        // cout << p[i][1] << " " << p[i][0] << "\n";
    }

    vector<long long> b(n + 1);
    for (long long i = 1; i <= n; i++) {
        b[p[i][1]] = a[i];
    }
    for (long long i = 1; i <= n; i++) {
        // cout << b[i] << "\n";
    }
    vector<long long> sum(n + 1, 0);
    for (long long i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + b[i];
    }
    long long ans = 0;
    for (long long i = 0; i < q; i++) {
        ans += sum[s[i][1]] - sum[s[i][0] - 1];
    }
    cout << ans << "\n";

    return 0;
}