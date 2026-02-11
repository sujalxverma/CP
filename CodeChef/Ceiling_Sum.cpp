#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll ceil_div(ll n)
{
    if (n >= 0)
        return (n + 1) / 2;
    return n / 2; // C++ truncation already acts as ceil for negatives.
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << "0\n";
                }
        else if (a > b)
        {
            if (a % 2 == 0)
            {
                if (b % 2 == 1)
                {
                    ll x = b;
                    cout << ceil_div(b - x) + ceil_div(x - a) << "\n";
                }
                else
                {
                    ll x = b + 1;
                    cout << ceil_div(b - x) + ceil_div(x - a) << "\n";
                }
            }
            else
            {
                if (b % 2 == 1)
                {
                    ll x = b + 1;
                    cout << ceil_div(b - x) + ceil_div(x - a) << "\n";
                }
                else
                {
                    ll x = b;
                    cout << ceil_div(b - x) + ceil_div(x - a) << "\n";
                }
            }
        }
        else
        {
            if (b % 2 == 0)
            {
                if (a % 2 == 1)
                {
                    ll x = a;
                    cout << ceil_div(b - x) + ceil_div(x - a) << "\n";
                }
                else
                {
                    ll x = a + 1;
                    cout << ceil_div(b - x) + ceil_div(x - a) << "\n";
                }
            }

            else
            {
                if (a % 2 == 1)
                {
                    ll x = a + 1;
                    cout << ceil_div(b - x) + ceil_div(x - a) << "\n";
                }
                else
                {
                    ll x = a;
                    cout << ceil_div(b - x) + ceil_div(x - a) << "\n";
                }
            }
        }
    }
    return 0;
}