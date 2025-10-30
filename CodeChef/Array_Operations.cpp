#include "bits/stdc++.h"
using namespace std;

/*
    Previous codes failed b/c i was considering only one occurence of the max element.
*/

void solve()
{
    int n;
    cin >> n;
    vector<long long>a(n);
    bool f = false;
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
    long long maxi = *max_element(a.begin(),a.end());

    long long steps = n/2;

    for(int i = 0; i<n ; i++){
        if(maxi == a[i] && (i&1) == 0){
            f = true;
        }
    }
    if(f){
        cout<<maxi+steps<<"\n";
        return ;
    }
    cout<<maxi+steps-1<<"\n";
    
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