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
        string s;
        cin >> s;
        if (n & 1)
        {
            cout << "NO\n";
            continue;
        }
        vector<pair<int, char>> a(26, {0, 'a'});
        for (auto &x : s)
        {
            a[x - 'a'].first++;
            a[x - 'a'].second = x;
        }

        // check if any character has fr, > 50%.
        bool f = false;
        for (int i = 0; i < 26; i++)
        {
            if (a[i].first > (n / 2))
            {
                f = true;
                break;
            }
        }
        if (f)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        string ans = "";
        sort(a.begin(), a.end());
        for (int i = 0; i < 26; i++)
        {
            if (a[i].first == 0)
                continue;
            for (int j = 0; j < a[i].first; j++)
            {
                ans += a[i].second;
            }
        }
        reverse(ans.begin() + n / 2, ans.end());
        cout << ans << "\n";
    }
    return 0;
}