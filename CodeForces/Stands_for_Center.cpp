#include "bits/stdc++.h"
using namespace std;

int main() {
    string s;
    cin >> s;

    long long n = s.size();
    long long ans = 0;

    for (long long i = 0; i < n; i++) {
        if (s[i] == 'C') {
            ans += min(i + 1, n - i);
        }
    }

    cout << ans << '\n';

    return 0;
}