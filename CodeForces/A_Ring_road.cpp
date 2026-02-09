#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<char>s(110,0);
    vector<char>e(110,0);
    int sum  = 0;
    int cnt = 0;
    for(int i = 0; i < n ; i++){
        int u,v,k;
        cin >> u >> v >> k;
        if(s[u]) {
            e[u] = s[v] = 1;
            cnt += k;
        }

        sum += k;
    }


    return 0;
}