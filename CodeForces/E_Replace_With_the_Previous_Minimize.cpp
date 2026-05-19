#include "bits/stdc++.h"
using namespace std;

int find_set(int v, vector<int> &parent) {
    if (parent[v] == v)
        return v;
    return parent[v] = find_set(parent[v], parent);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> parent(26);

        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {

            int v = s[i] - 'a';

            // current smallest representative
            int cur = find_set(v, parent);

            while (k > 0 && cur > 0) {

                // connect current char to previous char
                parent[cur] = cur - 1;

                k--;

                // move to new representative
                cur = find_set(cur, parent);
            }

            if (k == 0)
                break;
        }

        // build final string
        for (int i = 0; i < n; i++) {
            int v = s[i] - 'a';
            v = find_set(v, parent);
            s[i] = char(v + 'a');
        }

        cout << s << '\n';
    }

    return 0;
}