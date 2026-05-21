#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a)
        cin >> it;

    sort(begin(a), end(a));

    if (a[0] * 2 >= a[n - 1]) {
        cout << 0 << "\n";
        return 0;
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        int id = upper_bound(begin(a), end(a), 2 * a[i]) - begin(a) - 1;
        if (id < 0) {
            continue;
        }
        ans = min(ans, n - 1 - id + i);
    }
    cout << ans << "\n";
    return 0;
}