#include "bits/stdc++.h"
using namespace std;
const int inf = 1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        pre[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[j] == s[i]) {
                pre[i][j] = 1;
            } else {
                break;
            }
        }
    }
    vector<vector<int>>dp(n+1,vector<int>(n+1,inf));
    for(int i = 0; i < n ; i++){
        dp[i][i] = 1;
    }
    for(int len = 2; len <= n ; len++){
        for(int i = 0 ; i <= n-len ; i++){
            int j = i+len-1;
            for(int k = )
        }
    }
    return 0;
}