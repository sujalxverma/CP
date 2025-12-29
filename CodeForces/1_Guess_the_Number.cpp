#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l = 1, r = 1000000;

    while (l < r) {
        int mid = (l + r + 1) / 2;

        // 1) print query
        cout << mid << '\n';
        cout.flush();   // 2) flush

        // 3) read response
        string response;
        cin >> response;

        // 4) process response
        if (response == "<") {
            r = mid - 1;
        } else { // ">="
            l = mid;
        }
    }

    // 5) final answer
    cout << "! " << l << '\n';
    cout.flush();       // 6) flush

    return 0;           // 7) exit immediately
}
