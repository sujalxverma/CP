#include "bits/stdc++.h"
using namespace std;

/*
1. After laying down all odd numbers, only evens remains.
2. For cases when multiplying factor is odd, say, 3rd mutiple of odd numbers, no element lays down, as all odd numbers
   already processed.
3. Now, even cases remain.
4. We only lay down cards, when mutiplying factors is some power 2.

*/

void solve()
{
    int n, k;
    cin >> n >> k;
    int f = 1;
    while ((n + 1) / 2 < k)
    {
        k -= (n + 1) / 2;
        n = n / 2;
        f *= 2;
    }
    // f -> power of 2 check.
    cout << (2 * (k)-1) * f << "\n";
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