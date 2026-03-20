#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int st = 0;
        int ed = n - 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                st = i;
                break;
            }
        }
        bool f = false;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                ed = i;
                break;
            }
        }

        if (st >= ed) {
            cout << "Bob\n";
            continue;
        }
        int seg = 0;
        int cnt = 0;
        for (int i = st; i <= ed; i++) {
            if (s[i] == '0') {
                cnt++;
            } else {
                if (cnt > 0) {
                    seg++;
                    cnt = 0;
                }
            }
        }

        if (cnt > 0) {
            seg++;
        }
        if (seg % 2 == 0) {
            cout << "Bob\n";
            continue;
        } else {
            cout << "Alice\n";
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}