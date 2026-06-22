#include "bits/stdc++.h"
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    unordered_map<int, int> lastindex;
    vector<int> dp(n, 1), parent(n, -1);
    for (int i = 0; i < n; i++) {
        if (lastindex.count(a[i] - 1)) {
            int idx = lastindex[a[i] - 1];
            dp[i] = 1 + dp[idx];
            parent[i] = idx;
        }
        if (!lastindex.count(a[i]) || dp[i] > dp[lastindex[a[i]]]) {
            lastindex[a[i]] = i;
        }
    }
    int idx = max_element(begin(dp), end(dp)) - begin(dp);
    cout << dp[idx] << "\n";
    int val = a[idx];
    vector<int> ans;
    while (idx != -1) {
        ans.push_back(idx + 1);
        idx = parent[idx];
    }
    reverse(begin(ans), end(ans));
    for (auto &X : ans) {
        cout << X << " ";
    }
    cout << "\n";
    return 0;
}