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
        if ((1 & n)) {
            for (int i = 0; i < n; i++) {
                cout << "55 ";
            }
            cout << "\n";
        } else {
            if ((n / 2) % 2 == 1) {
                for (int i = 0; i < n / 2; i++) {
                    cout << "4 6 ";
                }
            } else {
            }
            cout << "\n";
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}