#include "bits/stdc++.h"
using namespace std;

bool solve(const string &s) {
    stack<char> st;

    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();   
        } else {
            st.push(c);
        }
    }

    return st.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (solve(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}