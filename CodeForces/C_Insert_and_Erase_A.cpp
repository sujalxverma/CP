#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    string s, t;
    cin >> s >> t;
    string a1 = "";
    string b1 = "";
    // if(s == t){
    //     cout<<"0\n";
    //     return 0;
    // }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != 'A')
        {
            a1 += s[i];
        }
    }

    for (int i = 0; i < t.length(); i++)
    {
        if (t[i] != 'A')
        {
            b1 += t[i];
        }
    }

    if (b1 != a1)
    {
        cout << "-1\n";
        return 0;
    }

    vector<int> sf(26, 0), tf(26, 0);
    for (auto &x : s)
    {
        sf[x - 'A']++;
    }
    for (auto &x : t)
    {
        tf[x - 'A']++;
    }

    bool f = false;

    for (int i = 1; i < 26; i++)
    {
        if (tf[i] != sf[i])
        {
            f = true;
            break;
        }
    }

    if (f)
    {
        cout << "-1\n";
        return 0;
    }
    else
    {
        int ans = 0;
        vector<int> a;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != 'A')
            {
                a.push_back(cnt);
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }
        a.push_back(cnt);
        cnt = 0;
        vector<int> b;

        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] != 'A')
            {
                b.push_back(cnt);
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }
        b.push_back(cnt);

        for (int i = 0; i < a.size(); i++)
        {
            ans += abs(a[i] - b[i]);
        }
        cout << ans << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}