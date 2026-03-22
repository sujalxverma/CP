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

        int sta = -1;
        int edn = -1;
        for (int i = st; i <= ed; i++) {
            if (s[i] == '0' && sta == -1) {
                sta = i;
                edn = i;
            } else if (s[i] == '0' && sta != -1) {
                edn = i;
            }

            if (s[i] == '1' && sta != -1 && edn != -1) {
                break;
            }
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
        if (cnt == n) {
            cout << "Bob\n";
            continue;
        }
        if (cnt > 0) {
            seg++;
        }
        if (seg % 2 == 0) {
            cout << "Bob\n";
            continue;
        } else {
            cout << "Alice\n";
            cout << edn - st + 1 << "\n";
            for (int i = st + 1; i <= edn + 1; i++) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}