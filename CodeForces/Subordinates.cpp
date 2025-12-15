#include "bits/stdc++.h"
using namespace std;

/*
first create tree, then simply use dfs.
*/

int dfs(vector<vector<int>>&g , vector<int>&v , vector<int>&ans,int node){
    v[node] = 1;
    int count = 0;
    for(auto n : g[node]){
        if(v[n] == -1){
            count++;
            count += dfs(g,v,ans,n);
        }
    }

    return (ans[node] = count);

}


void solve(){
    int n;
    cin >> n;
    vector<vector<int>>g(n+1);
    for(int i = 2; i <= n ; i ++){
        int k;
        cin >> k;
        g[k].push_back(i);
    }
    // create adjacency list.
    vector<int>ans(n+1,0);
    vector<int>v(n+1,-1);

    ans[1] = dfs(g,v,ans,1);
    for(int i = 1 ; i <= n ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}