#include "bits/stdc++.h"
using namespace std;
using ll = long long;

// check if number can be formed or not.
bool check(string s)
{
    int n = (int)s.length();
    if (n % 2 != 0 && s[n / 2] != '0')
    {
        return false;
    }
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 0)
        {
            cout << "YES\n";
            continue;
        }
        ll bits = floor(log2(n)) + 1;

        string s = "";

        for (int i = 0; i < bits; i++)
        {
            if ((n & (1LL << i)) != 0)
            {
                s = '1' + s;
            }
            else
            {
                s = '0' + s;
            }
        }
        // cout << "\n";
        if (n == 0)
        {
            s = '0';
        }
        // cout << s << "\n";

        // check without appending zero.
        if (check(s))
        {
            // now make that number x.
            cout << "YES\n";
        }
        else
        {
            s = '0' + s;
            if (check(s))
            {
                // now make that number x.
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}