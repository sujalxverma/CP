#include "bits/stdc++.h"
using namespace std;

/*
1. Check if the two adjacent segements can be joined, then join them.
*/

void solve() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;

    int n = s.size();
    vector<pair<int,int>> segments;

    // Extract all continuous '1' segments
    for (int i = 0; i < n; ) {
        if (s[i] == '1') {
            int l = i;
            while (i < n && s[i] == '1') i++;
            int r = i - 1;
            segments.push_back({l, r});
        } else {
            i++;
        }
    }

    // If no mines at all
    if (segments.empty()) {
        cout << 0 << "\n";
        return;
    }

    // Cost to activate first segment
    int result = a;

    // Process gaps between segments
    for (int i = 0; i + 1 < segments.size(); i++) {
        int gap = segments[i + 1].first - segments[i].second - 1;
        int fill_cost = b * gap;

        if (fill_cost <= a) {
            result += fill_cost;
        } else {
            result += a;
        }
    }

    cout << result << "\n";
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
