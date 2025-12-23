#include "bits/stdc++.h"
using namespace std;

bool check(vector<int> &s, vector<int> &t)
{
    for (int i = 0; i < 26; i++)
    {
        if (s[i] > t[i])
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    string s, t;
    cin >> s >> t;
    vector<int> s_char(26, 0);
    vector<int> t_char(26, 0);
    for (int i = 0; i < (int)s.length(); i++)
    {
        s_char[s[i] - 'a']++;
    }
    for (int i = 0; i < (int)t.length(); i++)
    {
        t_char[t[i] - 'a']++;
    }

    if (!check(s_char, t_char))
    {
        cout << "Impossible" << "\n";
        return;
    }

    string ans = "";
    int pointer = 0;

    for (int i = 0; i < (int)t.length(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (t_char[j])
            {
                if (pointer < (int)s.size() && s[pointer] == char('a' + j))
                {
                    pointer++;
                    s_char[j]--;
                    t_char[j]--;
                    ans += char('a' + j);
                    break;
                }
                else
                {
                    t_char[j]--; // i am usin char(j).
                    if ((check(s_char, t_char)))
                    {
                        ans += char('a' + j);
                        break;
                    }
                    else
                    { // unnsuccesful to use, increment it again.
                        t_char[j]++;
                    }
                }
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}