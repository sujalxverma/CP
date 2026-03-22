#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;

    vector<vector<int>> f(26);
    /*
    1. s[i] == s[j]
    2. l <= (j - i) <= r;
    */

    for (int i = 0; i < n; i++) {
        f[s[i] - 'a'].push_back(i);
    }
    long long ans = 0;
    for (int i = 0; i < 26; i++) {
        auto &vec = f[i];

        for (int j = 0; j < vec.size(); j++) {
            int L = vec[j] + l;
            int R = vec[j] + r;

            // Find first index ≥ L
            auto it1 = lower_bound(vec.begin() + j + 1, vec.end(), L);

            // Find first index > R
            auto it2 = upper_bound(vec.begin() + j + 1, vec.end(), R);

            ans += 1LL * (it2 - it1);
        }
    }
    cout << ans << "\n";
}
