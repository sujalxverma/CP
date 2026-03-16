#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;
ll n, k, s, m;

bool f() {
    /*
    - Only when 1 < M < N.
    - For any case, if 2*M, is used, we can split it using : (M-1)+(M+1).
    - For odd, its not possible, possible for even only.
    - We split the range from [1 , M-1] and [M+1 , N]
    - Now, if we consider by choosing exactly X numbers from range 1, and remaining R = K-X numbers from
      range 2.
    - Min sum = X + (M+1)*R
    - Max sum = X*(M-1) + R*N.
    - Now, if S lies b/w Min sum and Max sum, then Yes, else check further.
    */

    for (ll x = 0; x <= k; x++) {
        ll minSum = x + (m + 1) * (k - x);
        ll maxSum = x * (m - 1) + (k - x) * n;

        if (minSum <= s && s <= maxSum) {
            return 1;
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k >> s >> m;

        if (1 < m && m < n) {
            if (f()) {
                cout << "0\n";
            } else {
                cout << "1\n";
            }

            continue;
        }

        if (m == 1) {
            for (ll x = 0; x <= k; x++) {
                ll remSum = s - x; // using x copies of 1.
                ll minSum = 2 * (k - x);
                ll maxSum = n * (k - x);

                if (minSum <= remSum && remSum <= maxSum) {
                    cout << x << "\n";
                    break;
                }
            }
            continue;
        }
        if (m == n) {
            for (ll x = 0; x <= k; x++) {
                ll remSum = s - x * n; // using x copies of n.
                ll minSum = 1 * (k - x);
                ll maxSum = (n - 1) * (k - x);

                if (minSum <= remSum && remSum <= maxSum) {
                    cout << x << "\n";
                    break;
                }
            }
            continue;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}