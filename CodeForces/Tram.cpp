#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int maxSeats = 0;
    int curr = 0;
    int diff = 0;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (i == 0) {
            maxSeats = v;
            curr = v;
        } else {
            curr -= u;
            curr += v;
            maxSeats = max(maxSeats, curr);
        }
    }
    cout << maxSeats << "\n";

    return 0;
}