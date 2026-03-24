#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    long long n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;

    long long blocks = sqrt(n);
    long long num_blocks = (n + blocks - 1) / blocks;

    vector<long long> up(num_blocks, 0);

    while (q--) {
        long long type;
        cin >> type;
        if (type == 1) {
            long long l, r, v;
            cin >> l >> r >> v;
            l--;
            r--;
            // left tail
            long long end = min(r, ((l / blocks) + 1) * blocks - 1);
            for (; l <= end; l++) {
                a[l] += v;
            }

            // full blocks
            for (; l + blocks - 1 <= r; l += blocks)
                up[l / blocks] += v;

            // right tail
            for (; l <= r; l++)
                a[l] += v;
        } else {
            long long idx;
            cin >> idx;
            idx--;
            cout << a[idx] + up[idx / blocks] << "\n";
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}