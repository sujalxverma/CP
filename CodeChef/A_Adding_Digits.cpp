#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k;
    cin >> n >> m >> k;
    ll digit = -1;
    for (ll i = 0; i <= 9; i++)
    {
        if ((n * 10 + i) % m == 0)
        {
            digit = i;
            break;
        }
    }
    if (digit == -1)
    {
        cout << "-1\n";
        return 0;
    }
    cout << n << digit;
    for (int i = 2; i <= k; i++)
    {
        cout << "0";
    }
    cout << "\n";

    return 0;
}