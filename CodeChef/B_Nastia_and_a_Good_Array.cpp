#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int mini = min_element(a.begin(), a.end()) - a.begin();
    int c = 1;
    int val = *min_element(a.begin(),a.end());
    vector<vector<int>>ans;
    for(int i = mini + 1 ; i < n ; i++){
        ans.push_back({mini+1 , i+1 , val , val + c});
        c++;
    }
    c = 1;
    for(int i = mini - 1; i >= 0 ; i--){
        ans.push_back({i+1 , mini+1 , val+c , val });
        c++;
    }
    cout<<n-1<<"\n";
    for(auto x : ans){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}