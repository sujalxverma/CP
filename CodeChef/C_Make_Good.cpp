#include "bits/stdc++.h"
using namespace std;

vector<long long>arr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        arr.resize(n);
        long long xorValue = 0;
        long long sum =0;
        for(int i = 0; i < n ; i++){
            cin >> arr[i];
            xorValue ^= arr[i];
            sum += arr[i];
        }
        cout<<2<<"\n";
        sum += xorValue;
        cout<<xorValue<<" "<<sum<<"\n";


    }
    return 0;
}