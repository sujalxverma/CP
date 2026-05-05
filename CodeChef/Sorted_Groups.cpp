#include "bits/stdc++.h"
using namespace std;

int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        set<int> st;
        vector<int> chars;
        int maxi = s[0] - 'a';

        for (int i = 1; i < n; i++) {
            if (s[i] - 'a' >= maxi) {
                maxi = s[i] - 'a';
            } else {
                st.insert(i);
                chars.push_back(s[i]);
            }
        }

        sort(rbegin(chars), rend(chars));

        for (auto &x : st) {
            s[x] = chars.back();
            chars.pop_back();
        }

        cout << s << "\n";
    }

    return 0;
}