#include "bits/stdc++.h"
using namespace std;

/*
1. The following string should be of the form Z : P + Q + R.
2. Where P->Prefix from s, S->Suffix from t, and Q->common part b/w them.
3. The shortest Z will be when |Q| = 1.
4. We work by calulating length, if it matches condition, if length is smaller, then we update s_i and t_i.
5. And finally form Z, if exist, otherwise return -1.
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    int n = (int)s.length();
    int m = (int)t.length();
    string result = "";
    vector<vector<int>> pos(26);
    for (int i = 0; i < m; i++)
    {
        pos[t[i] - 'a'].push_back(i);
    }
    int s_i = -1;
    int t_i = -1;
    int len = 1e9;
    for (int i = 1; i < n; i++)
    {
        char c = s[i];
        if ((int)pos[c - 'a'].size() == 0)
        {
            continue;
        }
        int j = pos[c - 'a'].back(); // largest index
        if (j == m - 1 && (int)pos[c - 'a'].size() == 1)
        {
            continue; // skip m-1 as intended
        }
        else if (j == m - 1 && (int)pos[c - 'a'].size() > 1)
        {
            j = pos[c - 'a'][(int)pos[c - 'a'].size() - 2];
        }

        int ans = (i + 1) + (m - j);
        if (ans < len)
        {
            s_i = i;
            t_i = j;
            len = ans;
        }
    }
    if (s_i == -1 || t_i == -1)
    {
        cout << "-1\n";
        return 0;
    }
    cout << s.substr(0, s_i + 1) + t.substr(t_i + 1) << "\n";
    return 0;
}