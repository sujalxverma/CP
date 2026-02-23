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
        int n;
        cin >> n;
        vector<string> a(n);
        map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]] = 1;
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < (int)a[i].length(); j++)
            {
                string s1 = a[i].substr(0, j + 1);
                string s2 = a[i].substr(j + 1);
                if (mp.count(s1) && mp.count(s2))
                {
                    ans[i] = 1;
                    break;
                }
            }
        }

        for (auto &x : ans)
        {
            cout << x;
        }
        cout << "\n";
    }
    return 0;
}