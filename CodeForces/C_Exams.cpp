#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    int best = -1;
    sort(begin(p), end(p));
    for (int i = 0; i < n; i++) {
        if (best <= p[i].second) {
            best = p[i].second;
        } else {
            best = p[i].first;
        }
    }
    cout << best << "\n";

    return 0;
}