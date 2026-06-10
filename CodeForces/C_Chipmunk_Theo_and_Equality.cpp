#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    if (s.size() == 1) {
        cout << "0\n";
        return;
    }
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int v = a[i];
        nums.push_back(v);
        while (v > 1) {
            v = (v & 1) ? v + 1 : v / 2;
            nums.push_back(v);
        }
    }
    // index compression.
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int m = (int)nums.size();
    vector<pair<int, int>> cnt(m, {0, 0});
    for (int i = 0; i < n; i++) {
        set<int> s;
        int v = a[i];
        s.insert(v);
        int count = 0;
        auto idx = lower_bound(begin(nums), end(nums), v) - begin(nums);
        // cnt[idx].first = max(count, cnt[idx].first);
        cnt[idx].first += count;
        cnt[idx].second++;
        v = (v & 1) ? v + 1 : v / 2;
        count++;
        while (!s.count(v)) {
            // v = (v & 1) ? v + 1 : v / 2;
            // count++;
            s.insert(v);
            idx = lower_bound(begin(nums), end(nums), v) - begin(nums);
            // cnt[idx].first = max(c/\ount, cnt[idx].first);
            cnt[idx].first += count;
            cnt[idx].second++;
            v = (v & 1) ? v + 1 : v / 2;
            count++;
        }
    }

    int ans = 1e9;
    for (int i = 0; i < m; i++) {
        if (cnt[i].second == n) {
            ans = min(ans, cnt[i].first);
        }
    }
    // for (int i = 0; i < m; i++) {
    //     cout << nums[i] << " " << cnt[i].first << " " << cnt[i].second << "\n";
    // }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}