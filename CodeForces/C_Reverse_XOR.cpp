#include "bits/stdc++.h"
using namespace std;
int reverse_bits(int x)
{
    int msb = 31 - __builtin_clz(x);
    int rev = 0;

    for (int i = 0; i <= msb; i++)
    {
        if ((x >> i) & 1)
        {
            rev |= (1 << (msb - i));
        }
    }
    return rev;
}

int num(int n)
{
    for (int x = 0; x <= 1e7; x++)
    {
        if (x == 0) {
            if (n == 0) return 0;
            continue;
        }

        int fx = reverse_bits(x);

        if ((x ^ fx) == n)
        {
            return x;
        }
    }
    return -1;
}


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
        int ans = num(n);
        if (ans == -1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n" ;
            cout<< ans << "\n";
        }
    }
    return 0;
}