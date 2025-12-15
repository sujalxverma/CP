// #include "bits/stdc++.h"
// using namespace std;


// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n);
//     for(auto &x : a){
//         cin >> x;
//     }
//     if(n == 1){
//         cout<< 1<<"\n";
//         return ;
//     }
    
//     int count = 0;
//     int c = 0;
//     for(auto &x : a){
//         if(x >= 2){
//             count++;
//             x = -1;
//         }else if(x == 1){
//             c ++;
//         }
//     }
//     count += (c+1)/2;
    
//     cout<<count<<"\n";

// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }

//Date: 10-12-2025 //Author: Rishabh Paul

// Standard C++ Libraries
#include<iostream>
#include<chrono>
#include<vector>
#include<map>
#include<thread>
#include<mutex>
#include<ctime>
// #include<bits/stdc++.h>
#include<set>
#include<unordered_set>
#include<sstream>
#include<fstream>
#include<random>
#define int long long
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define pb(a) push_back(a)
const int inf = (int)2e9 + 7;
const long long linf = (long long)2e18 + 18;
const int mod = (int)1e9 + 7;

using namespace std;
using namespace chrono;

//output operator for pair
template<typename K, typename V>
ostream &operator<<(ostream &os, const pair<K, V> &p) {
    os << p.first << " " << p.second << endl;
    return os;
}

// Utility function to print vector
template<typename T>
void print_vector(vector<T> &a, T add = T(0)) {
    for(T x: a) {
        cout << x + add << " ";
    }
    cout << endl;
}

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int &x: a) {
//         cin >> x;
//     }
//     int ans = inf;
//     for (int i = 0; i + 1 < n; i++) {
//         ans = min(ans, a[i] + a[i + 1]);
//     }
//     cout << ans << endl;
// }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int &x: a) {
        cin >> x;
    }
    int one = count(all(a), 1);
    int rest = n - one;
    int ans = (one + 1) / 2;
    ans += rest;
    cout << ans << endl;
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}