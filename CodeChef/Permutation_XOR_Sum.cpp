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
        long long n;
        cin >> n;
        long long ans = 0;
        while (n > 0)
        {
            long long highest_number = 0;
            if ((n & (n - 1)) == 0)
            {
                // n is some power of 2.
                long long k = __builtin_ctzll(n); // count trailing zeros
                highest_number = (1LL << (k + 1)) - 1;
            }
            else{
                long long k = ceil(log2(n));
                highest_number = (1LL << k) - 1;
            }

            
        }
    }
    return 0;
}