#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        // Special fast case
        if (k == 1) {
            cout << n * (n + 1) / 2 << '\n';
            continue;
        }

        ll ans = 0;

        queue<pair<ll,ll>>q;
        q.push({n,1});

        while(!q.empty()){
            auto [length , count] = q.front();
            q.pop();

            if(length > k && (length&1)==1){

                ll mid = (length+1)/2;
                // cout<<mid<<"\n";

                ans += (((count)) * ((2*mid) + (count-1)*(length+1)));
                q.push({mid-1,count*2});
            }
            else if(length > k){
                q.push({length/2 , 2*count});
            }
        }

        cout<<ans/2<<"\n";
       
    }

    return 0;
}
