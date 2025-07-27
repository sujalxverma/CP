#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rep2(i, a, b) for (long long i = a; i < b; i++)

void solve()
{
    ll n;
    cin >> n;
    vl a(n);
    rep2(i, 0, n) cin >> a[i];

    vector<char> b;
    bool f = true;
    ll i = 0;
    ll j = n - 1;

    // Alternate directions according to the pattern
    while (i < j)
    {
        if (f)
        {
            if (a[i] <= a[j])
            {
                b.push_back('L');
                b.push_back('R');
            }
            else
            {
                b.push_back('R');
                b.push_back('L');
            }
            f = false;
        }
        else
        {
            if (a[i] <= a[j])
            {
                b.push_back('R');
                b.push_back('L');
            }
            else
            {
                b.push_back('L');
                b.push_back('R');
            }
            f = true;
        }
        i++;
        j--;
    }
    if (i == j)
    {
        // To keep output always of length n
        if (f)
            b.push_back('L'); // pattern may be 'L' or 'R', pick one (problem statement needed)
        else
            b.push_back('R');
    }

    // Output only the first n moves
    rep(i, 0, n)
    {
        cout << b[i] << "";
    }
    cout << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
