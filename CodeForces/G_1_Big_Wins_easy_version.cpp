#include "bits/stdc++.h"
using namespace std;

int getMaxMedMinDiff(vector<int> &a) {
    int n = a.size();
    int ans = 0;

    // Brute-force through all subarrays up to length 200
    for (int i = 0; i < n; ++i) {
        vector<int> temp;
        for (int j = i; j < min(n, i + 200); ++j) {
            temp.push_back(a[j]);
            sort(temp.begin(), temp.end());

            int k = temp.size();
            int median = temp[(k - 1) / 2];  // 0-based index
            int minimum = temp[0];

            ans = max(ans, median - minimum);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        cout << getMaxMedMinDiff(a) << '\n';
    }

    return 0;
}
