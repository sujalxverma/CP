#include <iostream>
#include <vector>
using namespace std;

/*
Linear Sieve : O(N)
*/

vector<int> linearSieve(int n)
{
    vector<int> primes;
    vector<int> isPrime(n + 1, 1);

    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
            primes.push_back(i);

        for (int j = 0; j < (int)primes.size() && i * primes[j] <= n; j++)
        {
            isPrime[i * primes[j]] = 0;

            if (i % primes[j] == 0)
                break;
        }
    }

    return primes;
}

/*
Normal Sieve
-------------
Finds all prime numbers between 1 and n.

Time Complexity  : O(n log log n)
Space Complexity : O(n)
*/
vector<int> sieve(int n)
{
    vector<int> f(n + 1, 0);

    // 0 -> prime
    // 1 -> composite

    f[0] = f[1] = 1;

    for (int i = 2; i * i <= n; i++)
    {
        if (f[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                f[j] = 1;
            }
        }
    }

    vector<int> primes;

    for (int i = 2; i <= n; i++)
    {
        if (f[i] == 0)
            primes.push_back(i);
    }

    return primes;
}

/*
SPF Sieve (Smallest Prime Factor)
---------------------------------
spf[x] stores the smallest prime factor of x.

Example:
spf[12] = 2
spf[15] = 3
spf[49] = 7

Time Complexity  : O(n log log n)
Space Complexity : O(n)
*/

/*
using linear sieve for SPF.
vector<ll> linearSieve_SPF(ll n) {
    vector<ll> spf(n + 1, 0);
    vector<ll> primes;

    for (ll i = 2; i <= n; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }

        for (ll p : primes) {
            if (1LL * i * p > n || p > spf[i])
                break;

            spf[i * p] = p;
        }
    }

    return spf;
}
*/
vector<int> smallestPrimeFactor(int n)
{
    vector<int> spf(n + 1);

    // initially assume every number
    // is its own smallest prime factor
    for (int i = 0; i <= n; i++)
    {
        spf[i] = i;
    }

    spf[0] = 0;
    spf[1] = 1;

    for (int i = 2; i * i <= n; i++)
    {
        // if spf[i] == i,
        // then i is prime
        if (spf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                // first prime reaching j
                // is its smallest prime factor
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }

    return spf;
}

/*
Prime Factorization using SPF
------------------------------
Time Complexity : O(log n) : each division reduces n by at least a factor of 2.
*/
vector<int> primeFactors(int n, vector<int> &spf)
{
    vector<int> factors;

    while (n > 1)
    {
        int p = spf[n];
        factors.push_back(p);

        n /= p;
    }

    return factors;
}

/*
Euler Totient Function.
Using Linear Seive.
*/
vector<int> linearSieve_Phi(int n)
{ // Euler Totient Function
    vector<int> primes;
    vector<int> notprime(n + 1, 1);
    vector<int> phi(n + 1);

    notprime[0] = notprime[1] = 0;
    phi[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (notprime[i] == 1)
        {
            primes.push_back(i);
            phi[i] = i - 1; // i is prime
        }

        for (int j = 0; j < (int)primes.size() && i * primes[j] <= n; j++)
        {
            notprime[i * primes[j]] = 0;

            if (i % primes[j] == 0)
            {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            else
            {
                phi[i * primes[j]] = phi[i] * phi[primes[j]];
            }
        }
    }

    return phi;
}