#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto &x : b)
        cin >> x;
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    if (a[0] > b[m - 1]) {
        cout << 3 * n << ":" << 2 * m << "\n";
        return 0;
    }
    if (a[n - 1] < b[0]) {
        cout << 3 * n << ":" << 3 * m << "\n";
        return 0;
    }

        return 0;
}