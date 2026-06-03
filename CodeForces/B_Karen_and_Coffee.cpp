#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int MAXN = 2e5 + 10;

    int n, k, q;
    cin >> n >> k >> q;
    vector<int> da(MAXN, 0);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        da[l]++;
        da[r + 1]--;
    }
    vector<int> p(MAXN, 0);
    for (int i = 1; i < MAXN; i++) {
        p[i] = p[i - 1] + da[i];
    }
    vector<int> pr(MAXN, 0);
    for (int i = 1; i < MAXN; i++) {
        pr[i] = pr[i - 1] + (p[i] >= k ? 1 : 0);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int cnt = 0;
        cout << pr[r] - pr[l - 1] << "\n";
    }

    return 0;
}