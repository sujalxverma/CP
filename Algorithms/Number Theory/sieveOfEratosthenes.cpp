#include <iostream>
#include <vector>
using namespace std;

/*
-Finds all prime number b/w 1 and n.
-Time Complexity : O(nloglogn)
-Space Complexity : O(n)
*/
vector<int> sieve(int n)
{
    vector<int> f(n + 1, 0); // mark all numbers as 0, means all are prime.

    for (int i = 2; i * i <= n; i++)
    {
        if (f[i] == 0)
        {
            // means this number i is a prime.
            // mark all factors of i to be non prime.
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