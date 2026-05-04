#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(begin(a) + 1, end(a));

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] * 2 <= a[n]) {
            // do nothing
        } else {
            idx = i;
            break;
        }
    }
    idx--;
    cout << (n - idx) + (n - idx > idx ? 0 : (idx) - (n - idx)) << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}