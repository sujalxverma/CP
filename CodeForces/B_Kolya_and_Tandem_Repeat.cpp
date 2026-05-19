#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int add;
    cin >> add;
    int n = (int)s.length();
    int maxAns = 0;
    for (int z = 0; z < n; z++) {
        for (int i = z; i < n; i++) {
            // string cpy = s.substr(0, i + 1);
            int j = z;
            int k = i + 1;
            while (j <= i && k <= n - 1) {
                if (s[j] == s[k]) {
                    // no problem
                } else {
                    break;
                }
                j++;
                k++;
            }
            if (j == i && k <= n - 1) {
                maxAns = max(maxAns, 2 * ((i - z) + 1));
            } else if (j < i && k == n) {
                int len = i - j + 1;
                if (add >= len) {
                    maxAns = max(maxAns, 2 * ((i - z) + 1));
                    if (len == n) {

                        maxAns += 2 * ((add - len) / 2);
                    }
                }
            }
        }
    }
    cout << maxAns << "\n";
    return 0;
}