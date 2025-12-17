#include "bits/stdc++.h"
using namespace std;

using ll = long long ;
long long nCr(int n, int r)
{
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;

    r = min(r, n - r);  // use symmetry
    long long res = 1;

    for (int i = 1; i <= r; i++)
    {
        res = res * (n - r + i) / i;
    }
    return res;
}

unsigned long long factorial(int n)
{
    unsigned long long f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll half = n / 2;

    ll ans =
        (nCr(n, half) / 2) *
        factorial(half - 1) *
        factorial(half - 1);

    cout << ans << "\n";
    return 0;
}
