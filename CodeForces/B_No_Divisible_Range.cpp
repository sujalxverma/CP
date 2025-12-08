#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>p(n);
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
    p[0] = a[0];
    for(int i = 1; i< n ;i++){
        p[i] = p[i-1] + a[i];
    }
    int count = 0;
    for(int i = 0; i < n ; i++){
        for(int j = i ; j < n ;j ++){
            int sum = p[j];
            if(i > 0){
                sum -= p[i-1];
            }
            bool f = true;
            for(int k = i ; k <= j ; k++){
                if(sum % a[k] == 0){
                    f = false;
                    break;
                }
            }
            if(f == true){
                count++;
            }
        }
       
    }
     cout<<count<<"\n";
    return 0;
}