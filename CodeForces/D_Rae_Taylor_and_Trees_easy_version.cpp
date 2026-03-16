#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
vector<int> a, p, s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        a.resize(n);
        p.resize(n);
        s.resize(n);
        for (auto &x : a) {
            cin >> x;
        }

        p[0] = a[0];
        for (int i = 1; i < n; i++) {
            p[i] = min(p[i - 1], a[i]);
        }
        s[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            s[i] = max(s[i + 1], a[i]);
        }
        bool f = true;
        for (int i = 1; i < n; i++) {
            if (p[i - 1] > s[i]) {
                f = false;
                break;
            }
        }

        if (f)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}