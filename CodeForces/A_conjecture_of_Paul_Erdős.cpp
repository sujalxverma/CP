// VERMA
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

//------------------------------------------------------------------------------------------------------------//
//                                          Here you go

vector<bool> f(1e7 + 1, false);
// to get all primes from 1 to n.
void sieveOfEratosthenes(ll n)
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

    for (ll i = 2; i <= n; i++)
    {
        if (!numbers[i])
        {
            f[i] = true;
        }
    }
}
ll N = 1e7;
set<ll> found;
vector<bool> prefixCheck(1e7 + 1, false);
ll maxX = (ll)floor(sqrt(1e7));
ll maxY = (ll)floor(sqrt(maxX));
vector<ll> prefix(1e7 + 1, 0);

void helper()
{

    for (ll i = 1; i <= maxY; i++)
    {
        ll a = i * i * i * i;
        ll maxX = (ll)floor(sqrt(N - a));

        for (ll j = 1; j <= maxX; j++)
        {
            ll b = j * j;
            ll s = a + b;
            if (prefixCheck[s] == 1)
            {
                continue;
            }
            if (f[s] == 1)
            {
                prefixCheck[s] = 1;
            }
        }
    }

    prefix[0] = prefixCheck[0];
    for (ll i = 1; i <= N; i++)
    {
        prefix[i] = prefix[i - 1] + prefixCheck[i];
    }
}

void solve()
{
    ll n;
    cin >> n;
    cout << prefix[n] << "\n";
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    // precompute sieve.
    sieveOfEratosthenes(1e7 + 1);
    helper();
    while (t--)
    {
        solve();
    }
}
