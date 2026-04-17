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
        // int len = 0;
        // string g;

        // for (int i = 0; i < n; i++) {
        //     string s = "";
        //     for (int j = 0; j <= i; j++) {
        //         s += '1';
        //     }
        //     for (int j = i + 1; j < n; j++) {
        //         s += '0';
        //     }
        //     sort(begin(s), end(s));

        //     do {
        //         int ans = 0;
        //         set<int> st;
        //         for (int ik = 0; ik < n; ik++) {
        //             for (int jk = ik + 1; jk < n; jk++) {
        //                 if (s[ik] != s[jk]) {
        //                     st.insert(ik + jk + 2);
        //                 }
        //             }
        //         }
        //         if (st.size() > len) {
        //             g = s;
        //             len = st.size();
        //         }

        //     } while (next_permutation(begin(s), end(s)));
        // }

        // cout << len << " : " << g << "\n";

        if (n == 2) {
            cout << "01\n";
        } else if (n == 3) {
            cout << "001\n";
        } else if (n == 4) {
            cout << "0110\n";
        } else {
            cout << "1";
            for (int i = 1; i <= n - 2; i++) {
                cout << "0";
            }
            cout << "1\n";
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}