#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set<pair<int, int>> p;
    int n, m;
    cin >> n >> m;
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        int r, c;
        cin >> r >> c;
        vector<pair<int, int>> dir = {
            {0, 0}, {0, 1}, {1, 0}, {1, 1}};
        bool f = true;
        for (auto [x, y] : dir)
        {
            if (p.find({r + x, c + y}) != p.end())
            {
                f = false;
                break;
            }
        }
        if (f == true)
        {
            count++;
            for (auto [x, y] : dir)
            {
                p.insert({r+x,y+c});
            }
        }
    }
    cout<<count<<"\n";
    return 0;
}