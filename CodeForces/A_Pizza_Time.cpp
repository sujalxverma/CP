// VERMA 
#include "bits/stdc++.h"
using namespace std;
#include <random>
#include <chrono>
#include <numeric>


using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<long long>;



void solve() {
    
    ll n;
    cin >> n;
    if( n == 3){
        cout<<1<<"\n";
        return ;
    }
    if( n == 2){
        cout<<0<<"\n";
        return ;
    }
    if( n == 1){
        cout<<0<<"\n";
        return ;
    }
    if(n%2 == 0){
        cout << (n-2)/2<<"\n";
    }else{
        cout << (n-1)/2<<"\n";
    }
}


int main() {

    int T = 1;
    if (!(cin >> T)) return 0;
    while (T--) solve();


   
    return 0;
}