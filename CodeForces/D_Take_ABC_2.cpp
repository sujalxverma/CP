#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    string s;
    cin >> s;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    int n = (int)s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
        {
            a.push_back(i);
        }
        if (s[i] == 'B')
        {
            b.push_back(i);
        }
        if (s[i] == 'C')
        {
            c.push_back(i);
        }
    }

    int ans = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int k = c.size() - 1;

    while (i >= 0 && j >= 0 && k >= 0)
    {
        // check C - > B -> A
        int c_idx = c[k];
        int b_idx = -1;
        while (j >= 0)
        {
            if (b[j] < c_idx)
            {
                b_idx = b[j];
                break;
            }
            j--;
        }

        if (b_idx == -1)
        {
            break;
        }

        int a_idx = -1;
        while (i >= 0)
        {
            if (a[i] < b_idx)
            {
                a_idx = a[i];
                break;
            }
            i--;
        }

        if (a_idx == -1)
        {
            break;
        }

        ans++;
        i--;
        j--;
        k--;
    }

    cout << ans << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}