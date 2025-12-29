#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s, a;
        cin >> s >> a;
        int i = 0;
        int j = 0;
        set<char> st = {'a', 'b', 'c', 'd', 'e'};
        while (i < n && j < m)
        {
            if (s[i] == a[j])
            {
                j++;
            }
            else if(s[i] == '?')
            {
                char ch;

                for (auto &x : st)
                {
                    if (x != a[j])
                    {
                        ch = x;
                        break;
                    }
                }
                s[i] = ch;
            }
            i++;
        }

        if (j == m)
        {
            cout << "-1\n";
        }
       else{
         cout << s << "\n";
       }
    }
    return 0;
}