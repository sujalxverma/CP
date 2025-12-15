#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n ; i++) cin >> a[i];
    int ans = 0;
    int count = 1;
    for(int i = 1; i < n ; i++){
        if(a[i] <= 2*a[i-1]){
            count++;
            ans = max(count , ans);
        }else{
            count = 1;
        }
    }
    ans = max(count , ans);
    if(ans == 0){
        cout<<"1\n";
        return 0;
    }
    cout<<ans<<"\n";
    return 0;
}