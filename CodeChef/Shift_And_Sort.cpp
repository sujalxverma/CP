#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool f = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                f = false;
            }
        }
        if (f) {
            cout << "Yes\n";
            continue;
        }

        for (int i = 0; i < n - 1;) {
            if (a[i] <= a[i + 1]) {
                // no problem.
                i++;
            } else {
                // new to make it balance.
                int diff = (a[i] - a[i + 1]);
                int change = (diff + 1) / 2;
                a[i] -= change;
                a[i + 1] += change;
                i += 2;
            }
        }
        f = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                f = false;
            }
        }
        if (f) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}