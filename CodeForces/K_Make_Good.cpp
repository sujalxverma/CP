#include "bits/stdc++.h"
using namespace std;
using ll = long long ;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int xorV = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            xorV = xorV ^ k;
            sum += 1LL * k;
        }
        sum += xorV;
        cout << 2 << "\n";
        cout << xorV<<" "<<sum<<"\n";
    }
    return 0;
}