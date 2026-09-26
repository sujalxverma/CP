#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n, 0);
    vector<char> c(n, 'a');
    vector<int> done(n, 0);
    vector<pair<int, int>> qr;
    for (int i = 0; i < q; i++)
    {
        int s;
        cin >> s;
        if (s == 1)
        {
            int x;
            cin >> x;
            x--;
            a[x] = (a[x] == 1 ? 0 : 1);
            qr.push_back({s, x});
        }
        else
        {
            char d;
            cin >> d;
            qr.push_back({s, d - 'a'});
        }
    }
    set<int> m;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            m.insert(i);
        }
    }

    for (int i = q - 1; i >= 0; i--)
    {
        auto [x, s] = qr[i];
        if (x == 1 && done[s] == 0)
        {
            a[s] ^= 1;

            if (a[s] == 0)   // its open, insert into set
                m.insert(s); // logn
            else             // its close, remove from set, if i do not remove, then it gets
                             // wrong color.
                m.erase(s);  // logn
        }

        else if (x == 2 && !m.empty())
        {
            for (auto &k : m)
            {
                done[k] = 1;
                c[k] = s + 'a';
            }
            m.clear();
        }
    }
    for (auto &x : c)
    {
        cout << x << "";
    }
    return 0;
}