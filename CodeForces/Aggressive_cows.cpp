#include "bits/stdc++.h"
using namespace std;

static inline bool canPlace(const vector<int>& a, int dist, int cows) {
    int n = (int)a.size();
    int cnt = 1;
    int last = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] - last >= dist) {
            cnt++;
            last = a[i];
            if (cnt >= cows) return true;
        }
    }
    return false;
}

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int low = 1;
    int high = a.back() ;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlace(a, mid, c)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if (!(cin >> t)) return 0;
    while (t--) solve();
}
