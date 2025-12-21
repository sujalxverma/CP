#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // Prefix max and suffix max
        vector<int> prefMax(n), suffMax(n);
        prefMax[0] = a[0];
        for (int i = 1; i < n; i++)
            prefMax[i] = max(prefMax[i - 1], a[i]);

        suffMax[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffMax[i] = max(suffMax[i + 1], a[i]);

        // Prefix distinct
        vector<int> prefDistinct(n), suffDistinct(n);
        unordered_set<int> seen;
        seen.reserve(n);

        for (int i = 0; i < n; i++) {
            seen.insert(a[i]);
            prefDistinct[i] = (int)seen.size();
        }

        // Suffix distinct
        seen.clear();
        for (int i = n - 1; i >= 0; i--) {
            seen.insert(a[i]);
            suffDistinct[i] = (int)seen.size();
        }

        int M = *max_element(a.begin(), a.end());
        vector<pair<int, int>> answers;

        // Candidate split 1: k = M
        if (M < n) {
            int k = M;
            if (k >= 1 && k < n) {
                if (prefMax[k - 1] == k &&
                    prefDistinct[k - 1] == k &&
                    suffMax[k] == n - k &&
                    suffDistinct[k] == n - k) {
                    answers.emplace_back(k, n - k);
                }
            }
        }

        // Candidate split 2: k = n - M
        if (n - M >= 1 && n - M < n && n - M != M) {
            int k = n - M;
            if (prefMax[k - 1] == k &&
                prefDistinct[k - 1] == k &&
                suffMax[k] == n - k &&
                suffDistinct[k] == n - k) {
                answers.emplace_back(k, n - k);
            }
        }

        // Output
        cout << answers.size() << "\n";
        for (auto &p : answers) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}
