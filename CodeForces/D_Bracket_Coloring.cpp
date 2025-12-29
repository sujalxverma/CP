#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int>prefix(n+1,0);
    for(int i = 1; i <= n ; i++){
        if(s[i-1] == '('){
            prefix[i] = prefix[i-1] + 1;
        }else{
            prefix[i] = prefix[i-1]-1;
        }
    }
    if(prefix[n] != 0){
       
        cout<<"-1\n";
        return ;
    }
    if(*min_element(prefix.begin() , prefix.end()) == 0 || *max_element(prefix.begin() , prefix.end()) == 0){
        cout<<"1\n";
        for(int i = 1 ; i<= n ; i++){
            cout<<1<<" ";
        }
        cout<<"\n";
        return;
    }


    cout<<2<<"\n";
    vector<int>ans;

    int curr = 0;

    while(curr < n){
        int w = (s[curr] == '(' ? 1 : 2);
       
        do{
            curr++;
            // int w = (s[curr] == '(' ? 1 : 2);
            ans.push_back(w);
        }while(prefix[curr] != 0);
    }   
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}