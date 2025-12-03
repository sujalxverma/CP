#include "bits/stdc++.h"
using namespace std;

/*
Y.
1. Use simple BFS, to find the shortest path of each node from 1.
2. Then for each type in k, finds its longest path.
3. Print it.
*/

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int>a(n+1);
    // 1 based indexing.
    for(int i = 1; i <= n ; i++){
        cin >> a[i];
    }
    vector<int>d(n+1,1e8);
    vector<vector<int>>g(n+1);
    for(int i = 0 ; i < m ; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>visited(n+1,-1);

    queue<pair<int,int>>q;
    q.push({1,0});
    visited[1] = 1;
    d[1] = 0;
    while(!q.empty()){
        auto value = q.front();
        q.pop();
        auto node = value.first;
        auto dis = value.second;

        for(auto neig : g[node]){
            if(visited[neig] == -1){
                visited[neig] = 1;
                q.push({neig,dis+1});
                d[neig] = dis + 1;
            }
        }
    }

   map<int,int>mp;

   for(int i = 1 ; i <= n ; i++){
        mp[a[i]]= 0;
   }
   for(int i = 1 ; i <= n ; i++){
    mp[a[i]] = max(mp[a[i]] , d[i]);
   }

   for(auto x : mp){
    cout<<x.second<<" ";
   }
   cout<<"\n";
   return ;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    solve();
    
    return 0;
}