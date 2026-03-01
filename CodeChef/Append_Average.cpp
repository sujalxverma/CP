#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

using ll = long long;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        ll k;
        cin >> k;
        ll sum = 0;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        sort(begin(a), end(a));
        ll mn = a[0];

        // If k == 0 (defensive safety)
        if (k == 0)
        {
            cout << sum << "\n";
            continue;
        }

        // If two smallest are equal
        if (a[0] == a[1])
        {
            cout << sum + k * mn << "\n";
            continue;
        }

        // First operation
        ll s = (a[0] + a[1] + 1) / 2;
        sum += s;
        k--;

        // Shrinking phase (logarithmic steps)
        while (k > 0)
        {
            ll next = (mn + s + 1) / 2;
            if (next == s)
                break;
            sum += next;
            s = next;
            k--;
        }

        // Remaining operations (stable phase)
        sum += k * s;

        cout << sum << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}