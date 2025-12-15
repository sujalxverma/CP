#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        map<int,int>mp;
        vector<int>a(n);
        for(auto &x : a){
            cin >> x;
            mp[x%m]++;
        }

        
        if(m == 1 || n == 1){
            cout<<1<<"\n";
            continue;
        }
        int count = 0;
        for(auto &x : mp){
            auto req = m - x.first;
            if(x.second == 0){
                continue;
            }
            if(x.first == 0){
                count ++;
                x.second= 0;
            }
            else if(req == x.first){
                count++;
                x.second = 0;
            }
            else if(mp[req] == 0){
                // count++;
            }else{
                if(mp[req] == x.second){
                    count++;
                    mp[req] = 0;
                    x.second = 0;
                }else{
                    if(x.second > mp[req]){
                       
                        x.second -= (mp[req]+1);
                        mp[req] = 0;
                    }else{
                         mp[req] -= (x.second+1);
                         x.second = 0;
                    }
                    count++;
                }
            }
        }

        for(auto x : mp){
            count += x.second;
            // cout<<x.first<<" "<<x.second<<"\n";
        }
        cout<<count<<"\n";
    }
    return 0;
}