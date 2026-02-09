#include "bits/stdc++.h"
using namespace std;

long long sum(long long n){

    long long s = 0;

    while( n > 0 ){
        s += (n%10);
        n = n/10;
    }

    return s;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,k;
    cin >> n >> k;
    int cnt = 0;
    for(long long i = 1; i <= n ; i++){
        if(sum(i) == k){
            cnt++;
        }
    }
    cout<<cnt<<"\n";

    return 0;
}