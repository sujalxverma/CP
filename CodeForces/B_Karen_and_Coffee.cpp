#include "bits/stdc++.h"
using namespace std;
/*]
    Atleast k, but i was doing equal to k , thats why it was wrong.
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k,q;
    cin >> n >> k >> q;

    vector<int>p(200007,0);
    for(int i = 0; i < n ; i++){
        int a,b;
        cin >> a >> b;
        p[a] ++;
        p[b+1] --;
    }
    vector<int>prefix(200007);
    prefix[0] = p[0];
    for(int i = 1 ; i < 200007 ; i++){
        prefix[i] = prefix[i-1] + p[i];
    }
    vector<int>check(200007,0);
    if(prefix[0] == k){
        check[0] = 1;
    }
    for(int i = 1 ; i <= 200007 ; i ++){
        if(prefix[i] >= k){
            check[i] = check[i-1] + 1;
        }else{
            check[i] = check[i-1] ;
        }
    }
    for(int i = 1 ; i <= q ; i++){
        int a,b;
        cin >> a >> b;
        cout<<check[b] - check[a-1]<<"\n";
    }

    return 0;
}