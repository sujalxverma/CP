#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;

/*
 * Count number of substrings of that do not contain string t as their subsequence.
 * How ?
 * Count substrings of s that has string t as their subsequence.
 * then subtract from total number of substrings of s.
 */

ll countSubstrings(string s, string t)
{
    int n = s.size(), m = t.size();

    vector<vector<int>> next_pos(n + 2, vector<int>(26, -1));

    for (int c = 0; c < 26; c++)
        next_pos[n][c] = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        next_pos[i] = next_pos[i + 1];
        next_pos[i][s[i] - 'a'] = i;
    }

    ll ans = 0;

    for (int l = 0; l < n; l++)
    {
        int pos = l;
        bool ok = true;

        for (int j = 0; j < m; j++)
        {
            if (pos >= n)
            {
                ok = false;
                break;
            }
            pos = next_pos[pos][t[j] - 'a'];
            if (pos == -1)
            {
                ok = false;
                break;
            }
            pos++;
        }

        if (ok)
        {
            int r = pos - 1;
            ans += (n - r);
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    string a, b;
    cin >> a >> b;
    ll n = (ll)a.length();
    cout << n * (n + 1) / 2 - countSubstrings(a, b) << "\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}