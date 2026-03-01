#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;

void solve()
{

    ll n;
    cin >> n;
    bool check = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            check = true;
            break;
        }
    }

    if (!check)
    {
        cout << "1\n";
        return;
    }
    int cnt = 0;
    ll temp = n;
    for (ll i = 2; i * i <= temp; i++)
    {
        while (temp % i == 0)
        {
            cnt++;
            temp /= i;
        }
    }
    if (temp > 1)
        cnt++;

    if (cnt == 0)
    {
        cout << "1\n";
        return;
    }
    if (cnt <= 2)
    {
        cout << "2\n";
        return;
    }
    cout << "3\n";
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