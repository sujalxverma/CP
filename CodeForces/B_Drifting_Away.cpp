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
        string s;
        cin >> s;
        int n = s.length();
        bool f = false;
        if (n == 1 && s[0] == '*')
        {
            cout << 1 << "\n";
            continue;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '*' && s[i + 1] == '<')
            {
                f = true;
                break;
            }
            else if (s[i] == '>' && s[i + 1] == '*')
            {
                f = true;
                break;
            }
            else if (s[i] == '>' && s[i + 1] == '<')
            {
                f = true;
                break;
            }
            else if (s[i] == '*' && s[i + 1] == '*')
            {
                f = true;
                break;
            }
        }
        if (f)
        {
            cout << "-1\n";
        }
        else
        {
            int ans = 0;
            int count = 1;
            bool f = false;
            string c = s;
            
            if (s[0] == '*')
            {
                s[0] = '>';
                f = true;
            }
            for (int i = 1; i < n; i++)
            {
                if (s[i] == '*')
                {
                    s[i] = '>';
                }
                {
                    if (s[i] == s[i - 1])
                    {
                        count++;
                    }
                    else
                    {
                        ans = max(ans, count);
                        count = 1;
                    }
                }
            }
            s = c;
            ans = max(count, ans);
            count = 1;
            if (f)
            {
                s[0] = '<';
            }
            for (int i = 1; i < n; i++)
            {
                if (s[i] == '*')
                {
                    s[i] = '<';
                }
                {
                    if (s[i] == s[i - 1])
                    {
                        count++;
                    }
                    else
                    {
                        ans = max(ans, count);
                        count = 1;
                    }
                }
            }
            ans = max(count, ans);
            cout << ans << "\n";
        }
    }
    return 0;
}