#include "bits/stdc++.h"
using namespace std;
#define int long long
int f(vector<int> &a, int m, int x) {
    int sum = 0;
    int n = (int)a.size();
    for (int i = 0; i < n; i++) {
        sum += min(x, a[i]);
    }
    return (sum <= m);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    // assert(n > 0);
    if (sum <= m) {
        cout << "infinite\n";
        return 0;
    }

    int s = 0;
    int e = 1e18;
    int ans = 0;
    while (s <= e) {
        int x = s + (e - s) / 2;
        if (f(a, m, x)) {
            ans = x;
            s = x + 1;
        } else {
            e = x - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}