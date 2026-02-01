#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    if (n >= k) {
        cout << 0 << "\n";
        return 0;
    }

    int sum = n;
    int cnt = 0;

    while (sum < k) {
        cnt++;
        sum += (n + cnt);
    }

    cout << cnt << "\n";
    return 0;
}
