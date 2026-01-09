#include "bits/stdc++.h"
using namespace std;
using ll = long long;
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
        ll x;
        cin >> x;
        vector<char> check(32, 0);
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            // MSB -> LSB
            for (int j = 31; j >= 0; j--)
            {
                if (a[i] & (1LL << j))
                {
                    if (check[j])
                    {
                        // was set by some other element.
                        // completes a previously started toggle for this bit
                        // no new operation is consumed
                        check[j] = 0;  // neutralise
                        a[i] ^= (1LL << j);
                    }
                    else if (x > 0 && check[j] == 0 && i != n - 1)
                    {
                        // start a new toggle for this bit (consumes one operation)
                        check[j] = 1; 
                        a[i] ^= (1LL << j);
                        x--;
                    }
                }
            }
        }

        // if some toggle remains in check, then we can toggle it to last element,
        // pair all remaining unmatched toggles with the last element

        for (int i = 0; i <= 31; i++)
        {
            if (check[i])
            {
                a[n - 1] ^= (1LL << i);
            }
        }

        // special case for n = 2, but only when x > 0
        // but why ? see when n == 2, we really do not have any bit-dump element, to put extra bits in.
        // cause we need to select two elements.
        if ((x & 1) && n == 2)
        {
            a[0] ^= 1;
            a[1] ^= 1;
        }

        for (auto &x : a)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}