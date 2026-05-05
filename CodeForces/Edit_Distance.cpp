#include "bits/stdc++.h"
using namespace std;
string a, b;
vector<vector<int>> dp;
int f(int i, int j) {
    if (i == 0)
        return j;
    if (j == 0)
        return i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (a[i - 1] == b[j - 1]) {
        return dp[i][j] = f(i - 1, j - 1);
    }

    return dp[i][j] = 1 + min({
                              f(i, j - 1),    // insert
                              f(i - 1, j),    // delete
                              f(i - 1, j - 1) // replace
                          });
}

int main(int args, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;
    int n = (int)a.length();
    int m = (int)b.length();
    dp.resize(n + 1, vector<int>(m + 1, -1));

    cout << f(n, m) << "\n";

    return 0;
}