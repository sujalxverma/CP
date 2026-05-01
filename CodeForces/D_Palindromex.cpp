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
        vector<int> a(2 * n);
        pair<int, int> pos = {-1, -1};
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
            if (a[i] == 0 && pos.first == -1) {
                pos.first = i;
            } else if (a[i] == 0 && pos.first != -1) {
                pos.second = i;
            }
        }
        int maxAns = 1;
        vector<int> mex(n + 1, 0);
        // consider pos.first to be centre, and check for palindrome.
        int l = pos.first;
        int r = pos.first;
        while (l >= 0 && r < 2 * n) {
            if (a[l] == a[r]) {
                mex[a[l]] = 1;
                l--;
                r++;
            } else {
                break;
            }
        }
        for (int i = 0; i <= n; i++) {
            if (mex[i] == 0) {
                maxAns = max(maxAns, i);
                break;
            }
        }

        // consider pos.second to be centre, and check for palindrome.

        mex.assign(n + 1, 0);
        l = pos.second;
        r = pos.second;
        while (l >= 0 && r < 2 * n) {
            if (a[l] == a[r]) {
                mex[a[l]] = 1;
                l--;
                r++;
            } else {
                break;
            }
        }
        for (int i = 0; i <= n; i++) {
            if (mex[i] == 0) {
                maxAns = max(maxAns, i);
                break;
            }
        }

        // consider both positions of 0, and check for palindrome.
        mex.assign(n + 1, 0);
        l = (pos.first + pos.second) / 2;
        r = (pos.first + pos.second + 1) / 2;

        while (l >= 0 && r < 2 * n) {
            if (a[l] == a[r]) {
                mex[a[l]] = 1;
                l--;
                r++;
            } else {
                break;
            }
        }
        for (int i = 0; i <= n; i++) {
            if (mex[i] == 0) {
                maxAns = max(maxAns, i);
                break;
            }
        }

        cout << maxAns << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time takenx: " << duration.count() << " microseconds\n";

    return 0;
}