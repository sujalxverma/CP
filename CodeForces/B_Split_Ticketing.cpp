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
    vector<vector<int>> a(n + 1, vector<int>(n + 1, -1));
    vector<int> inp;
    int x;
    while (cin >> x) {
        inp.push_back(x);
    }
    reverse(begin(inp), end(inp));
    // for (auto &x : inp) {
    //     cout << x << "\n";
    // }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {

            a[i][j] = inp.back();
            inp.pop_back();
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == -1) {
                a[i][j] = a[j][i];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= n; c++) {
            for (int b = 1; b <= n; b++) {
                if (b == i || c == i || c == b) {
                    continue;
                }
                if (a[i][b] + a[b][c] < a[i][c]) {
                    if (i < b && b < c) {
                        cout << "Yes\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "No\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}