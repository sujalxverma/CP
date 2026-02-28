#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

void solve()
{
    int w, h, a, b;
    cin >> w >> h >> a >> b;
    int x1, y1, x2, y2; // bottom left coordinates of two sheets already placed.
    cin >> x1 >> y1 >> x2 >> y2;

    vector<pair<int, int>> f1 = {
        {x1, y1}, {x1 + a, y1}, {x1, y1 + b}, {x1 + a, y1 + b}};

    vector<pair<int, int>> f2 = {
        {x2, y2}, {x2 + a, y2}, {x2, y2 + b}, {x2 + a, y2 + b}};

    int min_x_diff = 1e9;
    int min_y_diff = 1e9;

    for (auto &[x, y] : f1)
    {
        for (auto &[n, m] : f2)
        {
            min_x_diff = min(min_x_diff, abs(n - x));
        }
    }

    for (auto &[x, y] : f1)
    {
        for (auto &[n, m] : f2)
        {
            min_y_diff = min(min_y_diff, abs(m - y));
        }
    }

    if (x1 == x2)
    {
        if (min_y_diff % b == 0)
        {
            cout << "Yes\n";
            return;
        }
        else
        {
            cout << "No\n";
            return;
        }
    }

    if (y1 == y2)
    {
        if (min_x_diff % a == 0)
        {
            cout << "Yes\n";
            return;
        }
        else
        {
            cout << "No\n";
            return;
        }
    }
    if (min_x_diff % a == 0 || min_y_diff % b == 0)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
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