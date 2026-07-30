/*
 * Floyd Warshall, all pair shortest path.
 */
const int INF = 1e9;
void floyd()
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
/* TC : O(N*N*N)
 * To check neg cycle, at end of algo, just check dis[i][i] < 0, then neg cycle exist.
 * Using floyd War, as a reachability algo, dp[i][j] = dp[i][j] | (dp[i][k] & dp[i][k])
 * To construct path, path[i][j] = path[i][k], if intermediate path exist.
 */