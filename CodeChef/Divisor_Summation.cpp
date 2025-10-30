#include "bits/stdc++.h"
using namespace std;

const long long N = 1e6 + 9;

long long d[N] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(long long i = 1 ; i < N ; i++){
        for(long long j = i ; j < N ; j+=i){
            if( i == j){
               
                continue;
            }
            d[j] += i;
        }
    }
    while(t--){
        long long n;
        cin >> n;
        cout<<d[n]<<"\n";
    }
    return 0;
}