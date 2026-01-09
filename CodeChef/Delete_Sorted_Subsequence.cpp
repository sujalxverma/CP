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
        int b = 0;
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                b++;
            }
            else
            {
                b--;
            }
            if (b < 0)
            {
                idx = i;
                // before this idx, it was balanced.
                break;
            }
        }

        if (b == 0)
        {
            cout << "0\n";
            continue;
            // sab changa si.
        }
        if (b > 0)
        {
            cout << "1\n";
            // we have extra zeroes, that can be removed, in 1 operation.
            continue;
        }

        bool zero = false;
        bool one = false;
        // 0->+ , 1->-
        b = 0;
        for (int i = idx; i < n; i++)
        {
            if (s[i] == '1')
            {
                b--;
            }
            else
            {
                b++;
            }
            if (b < 0)
            {
                one = true;
                break;
                // 1 are more.
            }
        }
        b = 0;
        // 1 -> + , 0 -> -
        for (int i = n - 1; i >= idx; i--)
        {
            if (s[i] == '1')
            {
                b++;
            }
            else
            {
                b--;
            }
            if (b < 0)
            {
                zero = true;
                break;
            }
        }

        if (one && zero)
        {
            cout << "2\n";
        }
        else
        {
            cout << "1\n";
        }
    }
    return 0;
}