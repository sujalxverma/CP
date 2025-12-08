#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1); //  1 based
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a); // create graph reversely.
    }

    int q;
    cin >> q;
    vector<bool>v(n+1,0);
    while(q--){
        int a,b;
        cin >> a >> b;
        if(a==1){
            if(v[b] == 1){
                continue;
            }
            v[b] = 1;
            queue<int>q;
            q.push(b);
            while(!q.empty()){
                auto node = q.front();
                q.pop();

                for(auto neg : g[node]){
                    if(v[neg] == 0){
                        v[neg] = 1;
                        q.push(neg);

                    }
                }
            }
        }else{
            if(v[b] == 1){
                cout<<"Yes\n";

            }else{
                cout<<"No\n";
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}