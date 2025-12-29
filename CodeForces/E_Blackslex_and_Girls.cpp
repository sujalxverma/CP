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
        long long n, x, y;
        cin >> n >> x >> y;

        bool fa = false;
        bool fb = false;

        long long sum = 0;
        string s;
        cin >> s;

        long long a = 0;
        long long b = 0;

        for (long long i = 0; i < n; i++)
        {
            long long k;
            cin >> k;
            sum += k;

            if (s[i] == '0')
            {
                a += (k / 2) + 1;
                fa = true;
            }
            else
            {
                b += (k / 2) + 1;
                fb = true;
            }
        }

        if (x < a || y < b || (x + y) < sum)
        {
            cout << "No\n";
        }
        else
        {
            if (fa && fb)
            {
                cout << "Yes\n";
            }
            else if (fa)
            {
                if (x >= y + n)
                    cout << "Yes\n";
                else
                    cout << "No\n";
            }
            else if (fb)
            {
                if (x + n <= y)
                    cout << "Yes\n";
                else
                    cout << "No\n";
            }
        }
    }

    return 0;
}
