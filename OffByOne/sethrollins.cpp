// https://codeforces.com/blog/entry/97396

// Code 1.
// All possible subset sums,
// Here, sum of elements <= N (size of array), implies every element is <= N.
#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    vector<int> fr(N + 1, 0); // stores frequency.
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        fr[x]++;
    }

    vector<pair<int,int>>compressed;
    for(int i = 1 ; i <= N ; i++){
        if(fr[i] > 0){
            compressed.emplace_back(i,fr[i]);
        }
    }

    vector<int>dp(N+1,0); // maxSum can form is N, as mentioned above.
    dp[0] = 1;

    for(const auto &[w,k] : compressed){
        vector<int>ndp = dp;   // space optimsation DP, remember.
        for(int p = 0 ; p < w ; p++){ // remainders actually
            int sum = 0;

            for(int multiple = p, count = 0 ; multiple <= N ; multiple+=w, count++){
                // eg, start from 0, then go to (0+4), 4, then to 8,and so on, b/c next elemnt of this
                // group is w distance apart.
                if(count > k){
                    sum -= dp[multiple - w*count];
                    count--;
                }
                if(sum > 0) ndp[multiple] = 1;
                sum += dp[multiple];

            }
        }
        swap(dp,ndp);
    }

    cout<<"Possible Sums"<<"\n";
    for(int i = 0 ; i <= N ; i++){
        if(dp[i] > 0) cout<<i<<" ";
    }
    cout<<"\n";

    return 0;
}