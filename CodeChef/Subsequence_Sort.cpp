#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<ll> a;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        a.resize(n);
        for (auto &x : a)
        {
            cin >> x;
        }
        vector<ll>b(n); // max-array.
        b[0] = a[0];
        for(int i = 1; i < n ; i++){
            if(a[i] < a[i-1]){
                b[i] = b[i-1];
            }else{
                b[i] = a[i];
            }
        }
        ll max_bit = 0;
        for(int i = 31 ; i >= 0 ; i--){
            for(int j = 0 ; j < n ; j++){
                if((1LL << i)^(a[j]) == 0){
                    continue;
                }else{
                    max_bit = max(max_bit,1LL << i);
                }
            }
        }

        cout<<max_bit<<"\n";

    }
    return 0;
}