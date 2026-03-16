#include "bits/stdc++.h"

#include <chrono>

using namespace std;
using namespace std::chrono;
std::vector<pair<int, int>> a, c;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i + 1;
        }

        /*
        Find any three indices such that a[i] + a[j] != a[k].
        If all elements are equal, then answer is not possible.
        */

        sort(begin(a), end(a));
        c = a;
        a.erase(unique(a.begin(), a.end(),
                       [](auto &i, auto &j) {
                           return i.first == j.first;
                       }),
                a.end());

        if ((int)a.size() == 1) {
            cout << "-1\n";
            continue;
        }

        cout << c[(int)c.size() - 1].second << " " << c[1].second << " " << c[0].second << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}