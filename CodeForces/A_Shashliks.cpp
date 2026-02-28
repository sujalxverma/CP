#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

void solve()
{
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    if (k < a && k < b)
    {
        cout << "0\n";
        return;
    }
    int ans = 0;
    if (x < y)
    {
        if (k >= a)
        {
            int diff = (k - a);
            int q = diff / x;
            ans += q;
            k -= q * x;
            if (k >= a)
            {
                ans++;
                k -= x;
            }

            if (k >= b)
            {
                diff = (k - b);
                q = diff / y;
                ans += q;
                k -= q * y;
                if (k >= b)
                {
                    ans++;
                    k -= y;
                }
            }
            cout << ans << "\n";
            return;
        }
        else
        {
            if (k >= b)
            {
                int diff = (k - b);
                int q = diff / y;
                ans += q;
                k -= q * y;
                if (k >= b)
                {
                    ans++;
                    k -= y;
                }
            }
        }

        cout << ans << "\n";
        return;
    }

    else
    {
        swap(a, b);
        swap(x, y);
        if (k >= a)
        {
            int diff = (k - a);
            int q = diff / x;
            ans += q;
            k -= q * x;
            if (k >= a)
            {
                ans++;
                k -= x;
            }

           if (k >= b)
            {
                diff = (k - b);
                q = diff / y;
                ans += q;
                k -= q * y;
                if (k >= b)
                {
                    ans++;
                    k -= y;
                }
            }
            cout << ans << "\n";
            return;
        }
        else
        {
            if (k >= b)
            {
                int diff = (k - b);
                int q = diff / y;
                ans += q;
                k -= q * y;
                if (k >= b)
                {
                    ans++;
                    k -= y;
                }
            }
        }

        cout << ans << "\n";
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}