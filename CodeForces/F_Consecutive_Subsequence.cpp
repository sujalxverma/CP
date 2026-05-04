#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int n;
unordered_map<int, int> dp, indices;
vector<int> parent;
vector<int> a;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    parent.resize(n, -1);

    for (int i = 0; i < n; i++) {
        int val = a[i];
        if (dp.count(val - 1)) {
            if (dp[val] < 1 + dp[val - 1]) {
                dp[val] = 1 + dp[val - 1];
                parent[i] = indices[val - 1];
                indices[a[i]] = i;
            } else {
                // no need to change.
            }
        } else {
            dp[val] = 1;
            indices[val] = i;
            // no need to change parent[val] , as it points to -1.
        }
    }
    int best_val = -1;
    int best_len = 0;

    for (auto &[v, len] : dp) {
        if (len > best_len) {
            best_len = len;
            best_val = v;
        }
    }

    int cur = indices[best_val];
    vector<int> addr;

    while (cur != -1) {
        addr.push_back(cur);
        cur = parent[cur];
    }

    reverse(addr.begin(), addr.end());
    cout << addr.size() << "\n";
    for (auto &x : addr) {
        cout << x + 1 << " ";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}