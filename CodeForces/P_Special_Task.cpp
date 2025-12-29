#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int fr[26] = {0};
    ll ans = 1;
    bool alpha = false;
    int diff = 0;
    int count0 = 0;
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (i == 0)
        {
            if (s[i] == '?' || !isdigit(s[i]))
            {
                ans *= 9;
                if (s[i] != '?')
                {
                    fr[s[i] - 'A'] = 1;
                    alpha = true;
                    diff = 1;
                }
            }
        }
        else
        {
            if (s[i] == '?')
            {
                // ans *= 10;
                count0++;
            }
            else if (!isdigit(s[i]))
            {
                if (!fr[s[i] - 'A'])
                {
                    fr[s[i] - 'A'] = 1;
                    if (!alpha)
                    {
                        ans *= 10;
                        alpha = true;
                        diff = 1;
                    }
                    else
                    {
                        ans *= (10 - diff);
                        diff++;
                    }
                }
            }
        }
    }

    cout << ans ;
    for(int i = 0 ; i< count0 ; i++){
        cout<<"0";
    }
    cout<<"\n";
    return 0;
}
