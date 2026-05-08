#include <iostream>
#include <vector>
using namespace std;

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