#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;
    multiset<int> s;
    s.insert(x);
    auto mid = s.begin();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int size = (int)s.size();
        s.insert(a);
        if (size % 2 == 1) {
            // odd length
            if (a < *mid) {
                mid--;
            } else if (a >= *mid) {
                // no change
            }
        } else {
            if (a < *mid) {
                mid++;
            } else if (a >= *mid) {
                mid++;
            }
        }
        size = (int)s.size();
        s.insert(b);
        a = b;
        if (size % 2 == 1) {
            // odd length
            if (a < *mid) {
                mid--;
            } else if (a >= *mid) {
                // no change
            }
        } else {
            if (a < *mid) {
                mid++;
            } else if (a >= *mid) {
                mid++;
            }
        }
        cout << *mid << "\n";
    }

    return 0;
}