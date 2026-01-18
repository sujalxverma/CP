#include "bits/stdc++.h"
using namespace std;
vector<int> a;
const int inf = 1e9;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max_row = log2(n);
    vector<vector<int>> st(max_row + 1, vector<int>(n, inf));

    st[0] = a; // base case, make first row of sparse table to be the input array.

    for (int row = 1; row <= max_row; row++)
    {
        for (int col = 0; col + (1 << row) <= n; col++)
        {
            st[row][col] = min(st[row - 1][col], st[row - 1][col +( 1 << (row-1))]);
        }
    }

    while(q--){
        int l,r;
        cin >> l>> r;
        l--;r--;
        int ans = 1e9;
        int k = log2(r-l+1);
        int range_len = (r-l+1);

        for(int row = k ; row >= 0 ; row--){
            if((1<<row) <= range_len){
                ans = min(ans , st[row][l]);
                l += (1<<row);
                range_len -= (1<<row);
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}