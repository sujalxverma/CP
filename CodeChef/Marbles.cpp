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
        string s, p;
        cin >> s >> p;
        int count = 0;
        set<char> st = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < n; i++)
        {
            if (s[i] == p[i])
            {
                // both elements are same.
                continue;
            }
            else if (s[i] == '?' && p[i] == '?')
            {
                // then no need to change.
                continue;
            }
            if(s[i] == '?' || p[i] == '?'){
                continue;
            }
            if (st.find(p[i]) != st.end())
            {
                // if p[i] is vowel.
                // now check for s[i] is also a vowel.
                if (st.find(s[i]) != st.end())
                {
                    // if s[i] is also a vowel, then it will take 2 steps.
                    count += 2;
                }
                else
                {
                    count++;
                }
            }
            else
            {
                // if p[i] is a consonant.
                // now check for s[i] is also a vowel.
                if (st.find(s[i]) != st.end())
                {
                    // if s[i] is a vowel, then it will take 1 steps.

                    count += 1;
                }
                else
                {
                    // s[i] is also a consonant.
                    count += 2;
                }
            }
        }
        // now have to check the cases for : '?'
        
        cout << count << "\n";
    }
    return 0;
}