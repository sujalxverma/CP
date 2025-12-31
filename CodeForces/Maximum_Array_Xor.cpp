#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << 2 * ((1LL << n) - 1) * min({(1LL << (n - 1)), k}) << "\n";
    }
    return 0;
}