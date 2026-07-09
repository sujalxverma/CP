#include "bits/stdc++.h"
using namespace std;
/*
The relative order b/w a and c will remain same through out the string.
*/

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int a1 = 0, b1 = 0, c1 = 0, a2 = 0, b2 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a')
            a1++;
        if (s[i] == 'b')
            b1++;
        if (s[i] == 'c')
            c1++;
        if (t[i] == 'a')
            a2++;
        if (t[i] == 'b')
            b2++;
        if (t[i] == 'c')
            c2++;
    }

    if (a1 != a2 || b1 != b2 || c1 != c2) {
        cout << "NO\n";
        return;
    }
    string sg = "";
    string tg = "";
    for (int i = 0; i < n; i++) {
        if (s[i] != 'b')
            sg += s[i];
        if (t[i] != 'b')
            tg += t[i];
    }
    if (sg != tg) {
        cout << "NO\n";
        return;
    }
    // a can only shift right.
    vector<int> as, at, cs, ct;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a')
            as.push_back(i);
        if (t[i] == 'a')
            at.push_back(i);
        if (s[i] == 'c')
            cs.push_back(i);
        if (t[i] == 'c')
            ct.push_back(i);
    }
    int m = (int)as.size();
    int i = 0;
    int j = 0;
    while (i < m && j < m) {
        if (as[i] > at[j]) {
            cout << "NO\n";
            return;
        }
        i++;
        j++;
    }
    i = 0;
    j = 0;
    m = (int)cs.size();
    while (i < m && j < m) {
        if (cs[i] < ct[j]) {
            cout << "NO\n";
            return;
        }
        i++;
        j++;
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}