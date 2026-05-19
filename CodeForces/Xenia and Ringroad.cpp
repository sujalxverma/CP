#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int ptr = 1;
    long long count = 0;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        if (x == ptr) {
            continue;
        }
        if (x > ptr) {
            count += (long long)(x - ptr);
            ptr = x;
        } else {
            count += (long long)(n - ptr + 1 + (x - 1));
            ptr = x;
        }
    }
    cout << count << "\n";
    return 0;
}