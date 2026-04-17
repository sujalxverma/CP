#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        /*
        Find all bad arrays.
        Then greedily pick right endpoint.
        */
        vector<pair<int, int>> idx;
        for (int i = 0; i < n; i++) {
            map<int, int> mp;
            int count = 0;
            for (int j = i; j < n; j++) {
                mp[a[j]]++;
                if (mp[a[j]] == 1) {
                    count++;
                } else if (mp[a[j]] == 2) {
                    count--;
                }
                if (count == 0) {
                    idx.push_back({j, i});
                }
            }
        }
        // cout << idx.size() << "\n";
        // cout << idx[0].second << " " << idx[0].first;
        // return 0;

        int pick = -1;
        int ans = 0;
        sort(begin(idx), end(idx));

        for (int i = 0; i < (int)idx.size(); i++) {
            int r = idx[i].first;
            int l = idx[i].second;
            if (pick < l) {
                ans++;
                pick = r;
            }
        }

        cout << ans << "\n";
    }
}