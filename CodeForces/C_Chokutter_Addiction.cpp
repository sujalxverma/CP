#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    if(n == 0){
        cout<<k<<"\n";
        return 0;
    }
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll time = a[0];
    ll close = a[0];
    for (int i = 1; i < n; i++)
    {
        if (close + 100 >= a[i])
        {
            // still close
            continue;
        }
        else
        {
            time += a[i] - close - 100;
            close = a[i];
        }
    }

    time += (k > (close + 100) ? (k - close -100) : 0);
    cout << time << "\n";
    return 0;
}