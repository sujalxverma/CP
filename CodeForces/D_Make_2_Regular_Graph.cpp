#include "bits/stdc++.h"
using namespace std;

/*
simple graph of 2 degrees of each node, is a cyclic graph.
here n = 8, means either 1 or 2 component graph.
*/
// Brute force -> O(N! * N^2)
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    // making this upper triangular matrix.
    // we only want to store that their is an edge b/w (u and v), we always u<v, to make upper triangular matrix.

    vector<vector<int>> g(n, vector<int>(n, 0));

   
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (a > b)
        {
            swap(a, b);
        }
        g[a][b] = 1;
    }

    int ans = 100;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }

    do
    {
        {
            vector<vector<int>> f(n, vector<int>(n, 0));
            for (int i = 0; i < n; i++)
            {
                int u = a[i];
                int v = a[(i + 1) % n];
                if (u > v)
                {
                    swap(u, v);
                }
                f[u][v] = 1;
            }
            // now check mismatch.
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (f[i][j] != g[i][j])
                    {
                        count++;
                    }
                }
            }

            ans = min(ans, count);
        }

        // two cycle
        for (int d = 3; d <= n - 3; d++)
        {
            vector<vector<int>> f(n, vector<int>(n, 0));
            for (int i = 0; i < d; i++)
            {
                int u = a[i];
                int v = a[(i + 1) % d];
                if (u > v)
                {
                    swap(u, v);
                }
                f[u][v] = 1;
            }

            for (int i = 0; i < n-d; i++)
            {
                int u = a[i+d];
                int v = a[(i + 1) % (n-d)+d];
                if (u > v)
                {
                    swap(u, v);
                }
                f[u][v] = 1;
            }
            // now check mismatch.
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (f[i][j] != g[i][j])
                    {
                        count++;
                    }
                }
            }

            ans = min(ans, count);
        }

    } while (next_permutation(a.begin(), a.end()));
    cout<<ans<<"\n";
    return 0;
}