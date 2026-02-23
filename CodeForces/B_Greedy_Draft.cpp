#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<vector<int>>g(n);
    for(int i = 0 ; i < n ; i++){
        int k ; cin >> k;
        for(int j = 0; j < k ; j ++){
            int x;
            cin >> x;
            g[i].push_back(x);
        }
    }
    vector<int>ans;
    vector<int>fr(m+1 , 0);
    for(int i = 0; i < n ; i++){
        bool f = false;
        for(int j = 0; j < g[i].size() ; j++){
            if(fr[g[i][j]] == 0 ){
                ans.emplace_back(g[i][j]);
                fr[g[i][j]] = 1; 
                f = true;
                break;
            }
        }
        if(!f){
            ans.push_back(0);
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}