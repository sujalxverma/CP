#include "bits/stdc++.h"
using namespace std;
using ll = long long;

vector<ll> sieveOfEratosthenes(ll n)
{
    vector<ll> numbers(n + 1, 0); // 0 = prime, 1 = not prime

    for (ll i = 2; i * i <= n; i++)
    {
        if (numbers[i])
            continue;

        for (ll j = i * i; j <= n; j += i)
        {
            numbers[j] = 1; // mark as not prime
        }
    }

    vector<ll> primeFactors;
    for (ll i = 2; i <= n; i++)
    {
        if (!numbers[i])
        {
            primeFactors.push_back(i);
        }
    }

    return primeFactors;
}
vector<long long> primeFactors(long long n)
{
    vector<long long> f;
    for (int x = 2; x * x <= n; x++)
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<ll> primesNumbers = sieveOfEratosthenes(1e6 + 5);
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> prime = primeFactors(n);
        ll sum = 0;

        for (ll i = 0; (int)primesNumbers.size(); i++)
        {
            if (primesNumbers[i] <= prime[0])
            {
                sum += (n * primesNumbers[i]);
                continue;
            }
            break;
        }
        cout << sum << "\n";
    }

    return 0;
}