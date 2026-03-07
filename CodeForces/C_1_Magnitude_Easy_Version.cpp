#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &x : a) {
            cin >> x;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}