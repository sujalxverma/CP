#include "bits/stdc++.h"
using namespace std;

vector<int> a, b;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

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
        a.resize(n);
        b.resize(n - 1);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n - 1; i++)
        {
            b[i] = gcd(a[i], a[i + 1]);
        }
        /*
        If, for more than 2 positions gcd decreases, then answer is strictly No.
        */
        int cnt = 0;
        for (int i = 0; i < n - 2; i++)
        {
            if (b[i] > b[i + 1])
            {
                cnt++;
            }
        }
        if (cnt > 1)
        {
            cout << "NO\n";
            continue;
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}