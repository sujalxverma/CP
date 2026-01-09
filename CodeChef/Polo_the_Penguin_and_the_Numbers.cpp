#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int digits(long long x)
{
    if (x == 0)
        return 1;
    int cnt = 0;
    while (x)
    {
        cnt++;
        x /= 10;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        int digits_of_l = digits(l);
        int digits_of_r = digits(r);
        ll start = l;
        ll ans = 0;

        for (int i = digits_of_l; i <= digits_of_r; i++)
        {
            ll tens = 1;
            for (int j = 1; j <= i; j++)
            {
                tens *= 10;
            }
            tens--;
            // cout<<tens<<"\n";
            if (tens <= r)
            {
                ll sums = ((tens*(tens+1)/2   -  (start * (start-1)/2))%mod + mod)%mod;
                ans += (1LL * i * (sums)) % mod;
                // cout << ans << "\n";
                start = tens + 1;
            }
        }
        if (start <= r)
        {

            ll sums =  ((r*(r+1)/2   -  (start * (start-1)/2))%mod + mod)%mod;
            ans += (1LL * digits_of_r * sums) % mod;
        }
        cout << ans % mod << "\n";
    }
    return 0;
}