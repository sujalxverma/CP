#include "bits/stdc++.h"
using namespace std;
int n;
void solve() {

    cin >> n;
    vector<vector<char>> g(2, vector<char>(n));
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < n; i++) {
        g[0][i] = s1[i];
    }
    for (int i = 0; i < n; i++) {
        g[1][i] = s2[i];
    }
    int count = 1;
    for (int i = 0; i < n; i++) {
    }
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