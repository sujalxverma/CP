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
        vector<int> f(n * n + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                f[x]++;
            }
        }
        bool fr = false;
        for (int i = 0; i < n * n + 1; i++) {
            if (f[i] > (n * n) - n) {
                fr = true;
                break;
            }
        }

        if (!fr) {
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