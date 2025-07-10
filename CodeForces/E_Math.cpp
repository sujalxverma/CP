#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<long long> vl;

// Check if a number is prime
bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (int i = 3; i * i <= num; i += 2)
        if (num % i == 0)
            return false;
    return true;
}
// ------------------------------------------------------------------------------------
//                              Here we go
// Get prime factors of a number
vl primeFactors(ll n)
{
    vl f;
    for (ll x = 2; x * x <= n; x++)
    {
        while (n % x == 0)
        {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1)
        f.push_back(n);
    return f;
}

// Custom bit_ceil for unsigned long long
unsigned long long bit_ceil(unsigned long long x)
{
    if (x <= 1)
        return 1;
    x--;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    return x + 1;
}

void solve()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << " " << 0 << endl;
        return;
    }

    if (isPrime(n))
    {
        cout << n << " " << 0 << endl;
        return;
    }

    vl factors = primeFactors(n);
    map<ll, ll> freq;

    for (auto x : factors)
        freq[x]++;

    ll maxFreq = 0;
    for (auto [prime, count] : freq)
        maxFreq = max(maxFreq, count);

    int product = 1;
    for (auto [prime, _] : freq)
        product *= prime;

    if ((maxFreq & (maxFreq - 1)) == 0)
    {
        bool allEqual = all_of(freq.begin(), freq.end(), [&](auto &p)
                               { return p.second == maxFreq; });

        int operations = allEqual ? log2(maxFreq) : log2(maxFreq) + 1;
        cout << product << " " << operations << endl;
    }
    else
    {
        int operations = log2(bit_ceil(maxFreq)) + 1;
        cout << product << " " << operations << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
