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
        long long n, a, b;
        cin >> n >> a >> b;
        long long ans = 0;

        for (int i = n - 1; i >= 0; i--)
        {

            if (!(a & (1LL << i)) && !(b & (1LL << i)))
            {
                // both are unset
                ans += (1LL << i);
                continue;
            }
            if ((a & (1LL << i)) && (b & (1LL << i)))
            {
                // both are set
                continue;
            }
            else if (a & (1LL << i))
            {
                // only ith bit of a is set.
                for (int j = 0; j <= i - 1; j++)
                {
                    if (!(a & (1LL << j)) && !(b & (1LL << j)))
                    {
                        // both are unset
                        ans += (1LL << j);
                        continue;
                    }
                    if ((a & (1LL << j)) && (b & (1LL << j)))
                    {
                        // both are set
                        continue;
                    }
                    if (a & (1LL << j))
                    {
                        ans += (1LL << j);
                    }
                }
            }
            else
            {
                for (int j = 0; j <= i - 1; j++)
                {
                    if (!(a & (1LL << j)) && !(b & (1LL << j)))
                    {
                        // both are unset
                        ans += (1LL << j);
                        continue;
                    }
                    if ((a & (1LL << j)) && (b & (1LL << j)))
                    {
                        // both are set
                        continue;
                    }
                    if (b & (1LL << j))
                    {
                        ans += (1LL << j);
                    }
                }
            }
            break;
        }
        cout << ans << "\n";
    }
    return 0;
}