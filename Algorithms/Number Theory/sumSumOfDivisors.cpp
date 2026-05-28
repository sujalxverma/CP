
/*
Sum of sum of divisors of n.
First find all divisiors of n,
then for each divisor find its sum of divisors.
And find their total sum.
*/

using ll = long long;
ll power(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

ll sumSumDivisors(ll n)
{
    ll ans = 1;

    for (ll p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            int a = 0;
            while (n % p == 0)
            {
                n /= p;
                a++;
            }

            ll term = 0;
            for (int j = 0; j <= a; ++j)
            {
                term += (power(p, j + 1) - 1) / (p - 1);
            }

            ans *= term;
        }
    }

    if (n > 1)
    { // remaining prime
        ans *= (1 + (n + 1));
    }

    return ans;
}