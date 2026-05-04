#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long diff = a[n - 1] - a[0];
    cout << diff << " ";
    long long f1 = 0;
    for (long long i = 0; i < n; i++) {
        if (a[0] == a[i]) {
            f1++;
        }
    }
    long long f2 = 0;
    for (long long i = 0; i < n; i++) {
        if (a[i] == a[n - 1]) {
            f2++;
        }
    }
    if (a[0] == a[n - 1]) {
        cout << (f1 * (f1 - 1)) / 2 << "\n";
        return 0;
    }
    cout << (f1 * f2) << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}