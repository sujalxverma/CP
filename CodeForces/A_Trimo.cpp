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
    string s;
    cin >> s;
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'o') {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "\n";
    } else {

        cout << s.substr(idx) << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}