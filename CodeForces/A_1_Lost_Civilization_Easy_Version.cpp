#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
vector<int> a;
/*
We traverse from idx 1 to n-1.
We create an unordered_map for O(1) lookup for existence of a number.
Check conditions accordingly to understand easily.
*/
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
            cin >> a[i];
        }
        unordered_map<int, int> mp;
        mp[a[0]] = 1;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1] && mp.count(a[i] - 1)) {
                // no problem
                mp[a[i]] = 1;
            } else if (a[i] == a[i - 1] && !mp.count(a[i] - 1)) {
                // new key created.
                mp.clear();
                cnt++;
                mp[a[i]] = 1;
            } else if (a[i] - a[i - 1] == 1 && mp.count(a[i] - 1)) {
                // no problem.
                mp[a[i]] = 1;
            } else if (a[i - 1] > a[i] && mp.count(a[i] - 1)) {
                // no problem.
                mp[a[i]] = 1;
            } else if (a[i - 1] > a[i] && !mp.count(a[i] - 1)) {
                mp.clear();
                cnt++;
                mp[a[i]] = 1;
            } else if (a[i] - a[i - 1] > 1) {
                // new key created
                cnt++;
                mp.clear();
                mp[a[i]] = 1;
            }
        }
        cout << cnt << "\n";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";
    return 0;
}