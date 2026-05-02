#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

/*
If there were 0s at end of string, then one 0 remains in the final result.
Otherwsie the algo is clean and good.
*/

pair<string, string> gen(int n) {
    string s1 = "";
    string s2 = "";

    int i = 0;
    while (i < n) {
        if (i % 2 == 0) {
            s1 += '0';
            s2 += '1';
        } else {
            s1 += '1';
            s2 += '0';
        }
        i++;
    }

    return {s1, s2};
}

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
        auto [s1, s2] = gen(n);
        if (s1 == s || s2 == s) {
            cout << s << "\n";
            continue;
        }
        vector<int> count;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt++;
            } else {
                if (cnt > 0) {
                    count.push_back(cnt);
                    cnt = 0;
                } else {
                    cnt = 0;
                }
            }
        }
        if (cnt > 0) {
            count.push_back(cnt);
        }
        if ((int)count.size() == 0) {
            cout << s << "\n";
            continue;
        }
        string res = "";
        for (int i = 0; i < (int)count.size(); i++) {
            res += "01";
        }
        for (int i = 1; i <= n - (2 * (int)count.size()); i++) {
            cout << "0";
        }
        if (s[n - 1] == '0') {
            cout << res.substr(1, n - 1) + '0' << "\n";
        } else {
            cout << res << "\n";
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";
    return 0;
}