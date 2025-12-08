#include "bits/stdc++.h"

using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    ll ca, cb, la, lb;
    ca = 0;
    cb = 0;
    la = 0;
    lb = 0;
    ll ans = 0;
    for (int r = 0; r < n; r++)
    {

        if (s[r] == 'a')
        {
            ca++;
        }
        else
        {
            cb++;
        }

        while (lb <= r && cb >= b)
        {
            if (s[lb] == 'b')
            {
                cb--;
            }
            lb++;
        }

        while (la <= r && ca >= a)
        {
            if (s[la] == 'a')
            {
                ca--;
            }
            la++;
        }

        if (la > lb)
        {
            ans += (la - lb);
        }
    }

    cout << ans << "\n";
    return 0;
}
