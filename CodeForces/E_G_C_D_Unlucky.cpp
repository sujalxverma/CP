#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n), s(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        for (int j = 0; j < n; j++) {
            cin >> s[j];
        }
        if (n == 1) {
            if (p[0] == s[0]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }
        bool f = true;
        for (int i = 1; i < n; i++) {
            if (p[i - 1] % p[i] != 0) {
                f = false;
            }
        }
        if (!f) {
            cout << "NO\n";
            continue;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (s[i + 1] % s[i] != 0) {
                f = false;
            }
        }
        if (!f) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (p[i] % s[i] != 0 && s[i] % p[i] != 0) {
                f = false;
            }
        }
        if (!f) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}