#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int)s.length();
        vector<int> freq(26, 0);
        for (auto &ch : s) {
            freq[ch - 'A']++;
        }
        sort(rbegin(freq), rend(freq));
        int ans = 1e9; // if all characters are same.
        // for (auto &x : freq) {
        //     cout << x << " ";
        // }
        // cout << "\n";
        for (int i = 1; i <= 26; i++) {
            if (n % i != 0) {
                continue;
            }
            int each = n / i;

            int ops = 0;
            for (int j = 0; j < i; j++) {
                ops += max(0, each - freq[j]);
            }
            ans = min(ans, ops);
        }
        cout << ans << "\n";
    }
    return 0;
}