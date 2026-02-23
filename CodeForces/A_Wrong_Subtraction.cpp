#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = (int)s.length();
    string ans = "";
    int idx = n-1;
    for (int i = n - 1; i >= 0; i--)
    {
        int val = s[i] - '0' + 1; // to rewmove completely
        if (val <= k)
        {
            idx = i - 1;
            k -= val;
        }
        else
        {
            s[i] = char(((s[i] - '0') - k) + '0');
            break;
        }
        if (k == 0)
        {
            break;
        }
    }

    for (int i = 0; i <= idx; i++)
    {
        cout << s[i];
    }
    cout << "\n";

    return 0;
}