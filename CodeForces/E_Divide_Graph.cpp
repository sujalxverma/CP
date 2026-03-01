#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;
const ll mod = 998244353;

// Modular Exponention
ll mod_pow(ll base, ll exp)
{
    ll res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back({v, mod_pow(2, i + 1)});
        g[v].push_back({u, mod_pow(2, i + 1)});
    }


    // its simply grredy.
    // 2^1 + 2^2 ... + 2^i < 2^(i+1)  : simple calculation

    



    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}