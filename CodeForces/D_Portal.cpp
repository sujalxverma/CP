#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
vector<int> b;
vector<int> a;
vector<int> c;

void solve()
{
    a.clear();
    b.clear();
    c.clear();
    int n, x, y;
    cin >> n >> x >> y;
    b.resize(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = x; i <= y - 1; i++)
    {
        a.push_back(b[i]);
    }
    for (int i = 0; i < x; i++)
    {
        c.push_back(b[i]);
    }
    for (int i = y; i < n; i++)
    {
        c.push_back(b[i]);
    }

    auto it = min_element(a.begin(), a.end()); // O(n)
    rotate(a.begin(), it, a.end());            // O(n)

    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] < a[0])
        {
            cout << c[i] << " ";
        }
        else
        {
            for (auto &x : a)
            {
                cout << x << " ";
            }
            for (int j = i; j < c.size(); j++)
            {
                cout << c[j] << " ";
            }
            cout << "\n";
            return;
        }
    }

    for (auto &x : a)
    {
        cout << x << " ";
    }
    cout << "\n";
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