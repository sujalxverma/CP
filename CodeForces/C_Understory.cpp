#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int q;
    cin >> q;
    multiset<long long> s;
    while (q--) {
        int t;
        long long h;
        cin >> t >> h;
        if (t == 1) {
            s.insert(h);
        } else {
            auto it = s.upper_bound(h);
            s.erase(s.begin(), it);
        }
        cout << (int)s.size() << "\n";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}