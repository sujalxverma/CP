#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
vector<int> f(int n) {
    vector<int> ans;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i != (n / i)) {
                ans.push_back(n / i);
            }
        }
    }
    return ans;
}
const int mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    vector<int> p(m, b[0]);
    for (int i = 1; i < m; i++) {
        p[i] = p[i - 1] + b[i];
    }
    int sum = p[m - 1];
    // i%j
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> fact = f(i + 1);
        int val = 0;
        for (auto &x : fact) {
            val += b[x - 1];
        }
        ans = (ans + a[i] * ())
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}