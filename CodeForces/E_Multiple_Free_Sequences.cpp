#include "bits/stdc++.h"
using namespace std;


/*
1. Think in terms of graphs.
2. Currently at (x,y), then as per formula will move to (y , (a*y + b*x) % M).
3. Now how do i know if the state i am standing at is 0 or not.
4. If it is of the form (0,t) or (t,0), then it is failed state, so all the states linking to it will be
   discarded.
5. Simply reverse the directed edges of the graph and use BFS.
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, a, b;
    cin >> m >> a >> b;
    vector<vector<int>> g(m*m);
    vector<int> seen(m * m, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // (i,j)  ------>   (j , (a*j + b*i)%m)
            // reverse edge to see if we can reach from (0,t) to any (x,y)
            // converting to id, means converting to 1D, we can directly 2D matrix as well.
            int k = (a * j + b * i) % m;
            g[j * m + k].push_back((i * m + j));
        }
        
        
    }
    queue<int> q;
        // queue initialization.
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0)
                {
                    int v = i * m + j;
                    seen[v] = 1;
                    q.push(v);
                }
            }
        }

        // run bfs
        while (!q.empty())
        {
            int v = q.front();
            q.pop();

            for (int u : g[v])
            {
                if( ! seen[u]){
                    seen[u] = 1;
                    q.push(u);
                }
            }
            /* code */
        }

    // count answers.
    int ans = 0;
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < m ; j++){
            if(seen[i*m + j] == 0) ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}