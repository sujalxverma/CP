#include "bits/stdc++.h"
using namespace std;
using ll = long long;

/*

*/

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll maxi = *max_element(a.begin(), a.end());
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += maxi - a[i];
    }

    ll g = 0;
    for (int i = 0; i < n; i++)
    {
        g = gcd(g, maxi - a[i]);
    }

    cout << (sum) / g << " " << g << "\n";

    

    return 0;
}