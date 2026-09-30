#include "bits/stdc++.h"
using namespace std;
#define int long long

/*
Say, some part -> [....i,i+1,i+2,i+3...i+k,....] is contigous. eg->[...,4,5,6,7,..]
then that part can never be flat.
so we can skip all those part that are contigous.
*/
int32_t main() {
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

        for (int i = 0; i < n; i++) {
            a[i] = a[i] - i;
            // cout << a[i] << "\n";
        }
        sort(begin(a), end(a));
        set<int> k;
        for (int i = 0; i < n; i++) {
            // cout << a[i] << " ";
            k.insert(a[i]);
        }
        a.clear();
        for (auto x : k) {
            a.push_back(x);
        }
        int ans = 1;
        int s = 1;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] - a[i - 1] == 1) {
                s++;
                ans = max(ans, s);
            } else {
                s = 1;
            }
        }
        ans = max(ans, s);
        cout << ans << "\n";
    }

    return 0;
}