#include "bits/stdc++.h"
using namespace std;
using ll = long long;
vector<ll> ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n, sum;
        cin >> n >> sum;
        if (sum < n || sum > (n) * (n + 1) / 2)
        {
            cout << "-1\n";
            continue;
        }
        ll diff = sum - n;
        ll curr = 0;
        ll nsum = 0;
        for(int i = n-1; i >= 0 ; i --){
            if(curr == diff){
                break;
            }
            if(curr + i <= diff ){
                curr += i;
                ans.push_back(i+1);
                nsum += (i+1);
            }
        }

        int size = (int)ans.size();
        for(int i = 0; i < n - size ; i++){
            ans.push_back(1);
        }

        assert(nsum == sum);

        if(n == sum){
            cout<<"1\n";
            for(int i = 1; i < n ; i++){
                cout<<i<<" "<<i+1<<"\n";

            }
            return ;
        }

        vector<char>vis(n+1,1);

        cout<<ans[0]<<"\n";

        vis[ans[0]]=0;

        

    }
    return 0;
}