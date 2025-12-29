#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string q;
    while (getline(cin, q)) {
        if (q == "Is it rated?") {
            cout << "YES\n";
        } else if (q == "Is it hard?") {
            cout << "NO\n";
        } else {
            cout << "UNKNOWN\n";
        }
        cout.flush();
    }
    return 0;
}
