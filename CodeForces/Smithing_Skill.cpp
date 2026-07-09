#include "bits/stdc++.h"
using namespace std;
int n, m;
vector<vector<int>> a;
vector<int> c;
/*
Recursion.
either make weapon and return, or skip and move for next weapon,
its like subset.
also we sort both arrays.
*/
int f(int idx1, int idx2, vector<int> d) {

    if (idx1 >= n) {
        return 0;
    }
    int ans = 0;
    // check if can make weapon.
    if (a[idx1][1] <= c[idx2]) {
        // weapon can be made
        // and, then return also.
        // make and return weapon, then make again or move to next weapon.

        // skip and move to next
        int v1 = f(idx1 + 1, idx2, d);
        // use this item and then reduce its power too.
        d[idx2] -= a[idx1][0] + a[idx1][1];
        int v2 = max(2 + f(idx1, idx2, d), f(idx1 + 1, idx2, d));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    c.resize(m);

    a.resize(m, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i][1];
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    sort(begin(a), end(a));
    sort(begin(c), end(c));
    return 0;
}