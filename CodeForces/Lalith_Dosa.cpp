#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    long long cnt = 0;
    for (long long i = 1; i < n; i++) {
        if (a[i - 1] >= a[i]) {
            a[i] = a[i - 1] + 1;
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}