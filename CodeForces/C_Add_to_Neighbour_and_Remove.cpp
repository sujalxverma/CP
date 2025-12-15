#include "bits/stdc++.h"
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(auto &x : a){
        cin >> x;
    }
    int i = 0;
    int j = n-1;
    int count = 0;
    int prev = 0;
    while(i <= j){
        if(a[i] == a[j]){
            i++;
            j--;
        }
        else{
            if(a[i] > a[j]){
                a[j-1] += a[j];
                j--; 
                count++;
            }
            else{
                a[i+1] += a[i];
                i++;
                count++;
            }
        }
    }
    for(auto x : a){
        cout<<x<<" ";
    }
    cout<<"\n";
    cout<<count<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}