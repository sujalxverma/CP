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
        set<int> st;
        int c = 1;
        st.insert(c);
        for (int i = 0; i < n; i++) {
            if (s[c - 1] == 'R') {
                c++;
            } else {
                c--;
            }
            st.insert(c);
        }
        // for (auto &x : st) {
        //     cout << x << " ";
        // }
        // cout << "\n";
        cout << (int)st.size() << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}