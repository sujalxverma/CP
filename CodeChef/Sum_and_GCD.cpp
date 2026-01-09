#include "bits/stdc++.h"
using namespace std;
vector<int>a;

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
        for (auto &x : a)
            cin >> x;
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end()); // remove duplicates
        n = (int)a.size();

        if (n == 1)
        {
            cout << 2LL * a[0] << "\n";
        }
        else if (n == 2)
        {
            cout << a[0] + a[1] << "\n";
        }
        else
        {
            int g = 0;
            for (int i = 0; i < n - 2; i++)
            {
                g = gcd(a[i], g);
            }
            cout << max(gcd(a[n - 2], g) + a[n - 1], gcd(a[n - 1], g) + a[n - 2]) << "\n";
        }
    }

    return 0;
}