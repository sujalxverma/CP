#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;
/*
 * Finds factorial upto n.
 * Also find inverse factorial.
 */

// computes factorials upto N, and stores in vector

int mod_pow(int a, int b);
std::vector<long long> compute_factorials(int n)
{
    std::vector<long long> factorials(n + 1);
    factorials[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        factorials[i] = (factorials[i - 1] * i) % MOD;
    }
    return factorials;
}

// Computes inverse factorials up to n using precomputed factorials
std::vector<long long> compute_inv_factorials(int n, const std::vector<long long> &fact)
{
    std::vector<long long> inv_fact(n + 1);
    inv_fact[n] = mod_pow(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; --i)
    {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
    return inv_fact;
}

// computes inverse from 1 to N.
std::vector<int> compute_inverses(int n)
{
    std::vector<int> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        inv[i] = MOD - (int)((1LL * (MOD / i) * inv[MOD % i]) % MOD);
    }
    return inv;
}