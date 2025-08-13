#include "bits/stdc++.h"
using namespace std;


void solve(){
    long long x,y;
    cin>>x>>y;
    long long ans=x*y-y-x;
    if(ans==-1) ans=max(x,y)-1;
    if(ans==0)ans=2;
    cout<<ans<<endl;
    
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
}
