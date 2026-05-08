#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n;
    cin >> n;

    int d = 0;
    int u = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            d++;
        } else if (x == -1) {
            u++;
        }
    }

    vector<int> ans;

    if (d == 0 && u == 0) {
        ans.push_back(0);
    } else if (d == 0 && u > 0) {
        ans.push_back(1);
    } else if (d > 0 && u == 0) {
        ans.push_back(-1);
    } else if (d == 1 && u == 1) {
        ans.push_back(0);
    } else if (d > 1 && u == 1) {
        ans.push_back(-1);
        ans.push_back(0);
    } else if (d == 1 && u > 1) {
        ans.push_back(0);
        ans.push_back(1);
    } else {
        ans.push_back(-1);
        ans.push_back(0);
        ans.push_back(1);
    }

    // Print the possible values space-separated
    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}