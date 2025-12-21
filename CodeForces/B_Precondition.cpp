#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;

    cin >> s;
    cin >> t;

    set<char> st;
    for (auto c : t)
    {

        st.insert(c);
    }

    for (int i = 1; i < s.length(); i++)
    {
        if (isupper(s[i]))
        {
            if (st.find(s[i - 1]) == st.end())
            {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";

    return 0;
}