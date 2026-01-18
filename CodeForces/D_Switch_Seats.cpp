#include "bits/stdc++.h"
using namespace std;

/*
…,a,b,…,b,a,….
or
…,a,b,…,a,b,….

Any case that forms in this fashion, can be swapped.
Thus using 1 swap, 2 partners sit together.

*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        vector<vector<int>> f(n + 1);
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> a[i];
            f[a[i]].push_back(i);
        }

        set<pair<int, int>> ans;
        for (int i = 0; i + 1 < 2 * n; i++)
        {
            int A = a[i];
            int B = a[i + 1];

            if (f[A][0] + 1 == f[A][1])
                continue;
            ;
            if (f[B][0] + 1 == f[B][1])
                continue;

            vector<int> pos = {f[A][0], f[A][1], f[B][0], f[B][1]};
            sort(begin(pos), end(pos));

            if (pos[0] + 1 == pos[1] && pos[2] + 1 == pos[3])
            {
                ans.insert(minmax(A, B));
            }
        }

        cout << (int)ans.size() << "\n";
    }
    return 0;
}