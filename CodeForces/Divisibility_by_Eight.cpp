#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = (int)s.length();

    // 1 digit
    for (int i = 0; i < n; i++) {
        int x = s[i] - '0';

        if (x % 8 == 0) {
            cout << "YES\n";
            cout << x << '\n';
            return 0;
        }
    }

    // 2 digits
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            string a = "";
            a += s[i];
            a += s[j];

            int x = stoi(a);

            if (x % 8 == 0) {
                cout << "YES\n";
                cout << x << '\n';
                return 0;
            }
        }
    }

    // 3 digits
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {

                string a = "";
                a += s[i];
                a += s[j];
                a += s[k];

                int x = stoi(a);

                if (x % 8 == 0) {
                    cout << "YES\n";
                    cout << x << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "NO\n";

    return 0;
}