#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    string s;
    cin >> s;
    vector<int> f(26, 0);
    int n = (int)s.length();
    for (int i = 0; i < n; ++i) {
        f[s[i] - 'a']++;
    }
    int count = 0;
    int even = 0;
    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (f[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
        count += f[i];
    }

    if (even == 26 || even == 25) {
        cout << "First\n";
    } else {
        if (count % 2 == 0) {
            cout << "Second\n";
        } else {
            cout << "First\n";
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}