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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = 0;

        // if a < b < c < d
        if (a <= b && b <= c && c <= d) {
            ans += (b - a);
            a = b;
            ans += (c - a);
            b += c - a;
            ans += d - b;
        } else if (a <= b && c <= b && b <= d) {
            ans += (c - a);
            a = c;
            ans += (d - b);
        } else if (a <= b && c >= d) {
            ans += (b - a);
            a = b;
            ans += (b - d);
            a += b - d;
            ans += c - a;
        }
        if (a > b) {
            swap(a, b);
            swap(c, d);
            if (a <= b && b <= c && c <= d) {
                ans += (b - a);
                a = b;
                ans += (c - a);
                b += c - a;
                ans += d - b;
            } else if (a <= b && c <= b && b <= d) {
                ans += (c - a);
                a = c;
                ans += (d - b);
            } else if (a <= b && c >= d) {
                ans += (b - a);
                a = b;
                ans += (b - d);
                a += b - d;
                ans += c - a;
            }
        }

        cout << ans << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}