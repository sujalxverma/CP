#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

/*
FIRST LINE WILL HAVE ALL ODD NUMBERS, SAY 2*K NUMBERS
SECOND LINE WILL HAVE ALL EVEN NUMBERS WHICH ARE NOT ODD * (2 ^ 1).
THIRD LINE WILL HAVE ALL EVEN NUMBERS WHICH ARE NOT ODD * (2 ^ 2).
FOURTH LINE WILL HAVE ALL EVEN NUMBERS WHICH ARE NOT ODD * (2 ^ 3).



*/

int ans(int n, int k) {
    if (k <= (n + 1) / 2) {
        return 2 * (k)-1;
    }
    return 2 * ans(n / 2, k - (n + 1) / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << ans(n, k) << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}