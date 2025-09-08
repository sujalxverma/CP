// VERMA
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

void solve()
{
    int n;
    if (!(cin >> n))
        return;
    vi b(n);
    rep(i, 0, n) cin >> b[i];

    vector<vi> pigeonHoles(n + 1);
    rep(idx, 0, n)
    {
        int v = b[idx];
        if (v < 1 || v > n)
        {
            cout << -1 << "\n";
            return;
        }
        pigeonHoles[v].push_back(idx);
    }

    rep(v, 1, n + 1)
    {
        if ((int)pigeonHoles[v].size() % v)
        {
            cout << -1 << "\n";
            return;
        }
    }

    vi answerSticker(n, 0);
    int nextSticker = 1;

  
    rep(v, 1, n + 1)
    {
        auto &holes = pigeonHoles[v];
        for (int i = 0, m = (int)holes.size(); i < m; i += v)
        {
           
            rep(j, 0, v)
            {
                answerSticker[holes[i + j]] = nextSticker;
            }
            ++nextSticker;
        }
    }

   
    rep(i, 0, n)
    {
        cout << answerSticker[i] << (i + 1 == n ? '\n' : ' ');
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
