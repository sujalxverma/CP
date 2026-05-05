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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(begin(a), end(a));

    int firstRange = n / 2;
    int ans = n;
    int ptr = firstRange;
    for (int i = 0; i < firstRange; i++) {
        int v = a[i];
        while (ptr < n) {
            if (a[ptr] >= 2 * v) {
                ptr++;
                ans--;
                break;
            } else {
                ptr++;
            }
            if (ptr == n) {
                break;
            }
        }
        if (ptr == n) {
            break;
        }
    }

    cout << ans << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}