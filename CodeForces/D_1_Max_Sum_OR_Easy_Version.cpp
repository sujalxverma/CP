#include <iostream>
#include <vector>
using namespace std;
#include <cmath>
/*
Simple greedy approach.
If r is (1<<x)-1, something like this, then simply reverse order the number.
Else, can be constructed greedily, with starting from r to 0.
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        if (((r + 1) & (r)) == 0) {
            cout << 1LL * (r - l + 1) * (r) << "\n";
            for (int i = r; i >= 0; i--) {
                cout << i << " ";
            }
            cout << "\n";
        } else {
            vector<int> v(r + 1, -1);
            for (int i = r; i >= 0; i--) {
                if (v[i] != -1)
                    continue;
                if (i == 0) {
                    if (v[1] == 0) {
                        v[0] = 1;
                    } else {
                        v[i] = 0;
                        continue;
                    }
                }
                int bits = floor(log2(i)) + 1;
                int num = 0;
                for (int j = 0; j < bits; j++) {
                    if ((1 << j) & i) {
                        // do nothing
                    } else {
                        num |= (1 << j);
                    }
                }
                v[i] = num;
                v[num] = i;
            }
            long long ans = 0;
            for (int i = 0; i <= r; i++) {
                ans += 1LL * (v[i] | i);
            }
            cout << ans << "\n";
            for (int i = 0; i <= r; i++) {
                cout << v[i] << " ";
            }
            cout << "\n";
        }
    }
}