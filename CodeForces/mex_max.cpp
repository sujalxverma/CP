#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n);
        map<int, int> freq;

        int mx = 0;

        for (int &x : a) {
            cin >> x;
            freq[x]++;
            mx = max(mx, x);
        }

        vector<int> b;

        // put one maximum first
        b.push_back(mx);
        freq[mx]--;

        // put first occurrences of 0,1,2,...
        int cur = 0;

        while (freq[cur] > 0) {
            if (cur != mx) {
                b.push_back(cur);
                freq[cur]--;
            }
            cur++;
        }

        // remaining elements
        for (auto &[x, c] : freq) {
            while (c--) {
                b.push_back(x);
            }
        }

        long long ans = 0;

        int prefMax = 0;
        vector<int> seen(n + 5, 0);

        int mex = 0;

        for (int x : b) {
            prefMax = max(prefMax, x);

            if (x <= n) {
                seen[x] = 1;
            }

            while (seen[mex]) {
                mex++;
            }

            ans += prefMax + mex;
        }

        cout << ans << '\n';
    }
}