#include "bits/stdc++.h"
using namespace std;

using ll = long long ;
/*
  1. Atleast there is one number that has not been changed. 
  2. That will be the max number possible.
  3. Diff of maxSum - sum , should be divisible by y.
  4. Also (maxNum - A[i]) should also be divisible by z, b/c each person takes z sword of the same type.
  5. Find factors of diff, and store them.
  6. Then check for all the factors, this above condition. 
  7. The first y thatt satisifies the condition will be the answer.
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll>a(n);
    ll sum = 0;
    for(ll i = 0; i < n ; i++){
        cin >> a[i];
        sum += a[i];
    }
    ll maxSum = *max_element(a.begin() , a.end()) * n ;
    ll diff = maxSum - sum;
    ll e  = *max_element(a.begin() , a.end())  ;
    ll s = *max_element(a.begin() , a.end())  - *min_element(a.begin() , a.end()) ;
    vector<ll>nums;
    for(ll i = 1 ; i * i < diff ; i++){
        if(diff%i == 0){
            nums.push_back(i);
            nums.push_back(diff/i);
        }
    }
    sort(nums.begin(),nums.end());
    for(auto y : nums){
        if(diff % y == 0){
            ll z = diff/y;
            bool f = true;
            for(int i = 0 ; i < n ; i++){
                if((e  -  a[i])%z != 0){
                    f = false;
                    break;
                }
            }
            if(f == true){
                cout<<y<<" "<<z<<"\n";
                return 0;
            }
        }
    }

    return 0;
}