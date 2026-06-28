#include "bits/stdc++.h"
using namespace std;

string a, b;
int n, m;
vector<vector<int>> dp;

int f(int i, int j) {
    if (i < 0) {
        int cost = 0;
        for (int k = 0; k <= j; k++)
            cost += (b[k] - 'a' + 1);
        return cost;
    }

    if (j < 0) {
        int cost = 0;
        for (int k = 0; k <= i; k++)
            cost += (a[k] - 'a' + 1);
        return cost;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (a[i] == b[j])
        return dp[i][j] = f(i - 1, j - 1);

    int substitute = abs(a[i] - b[j]) + f(i - 1, j - 1);
    int remove = (a[i] - 'a' + 1) + f(i - 1, j);
    int insert = (b[j] - 'a' + 1) + f(i, j - 1);

    return dp[i][j] = min({substitute, remove, insert});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;

    n = a.size();
    m = b.size();

    dp.assign(n, vector<int>(m, -1));

    cout << f(n - 1, m - 1) << '\n';

    return 0;
}