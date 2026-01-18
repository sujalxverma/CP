#include "bits/stdc++.h"
using namespace std;
vector<int> nums;
const int inf = 1e9;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int max_row = log2(n);                                    // rows -> [0,max_row]
    vector<vector<int>> st(max_row + 1, vector<int>(n, inf)); // sparse table
    // same first row of st to be the same vector array.
    st[0] = nums;

    // fill the sparse table, minimum sparse table.
    for (int row = 1; row <= max_row; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (col + (1 << row) > n)
                continue; // it will remain infinity.
            st[row][col] = min(
                st[row - 1][col],
                st[row - 1][col + (1 << (row - 1))]);
        }
    }

    // for (int row = 0; row <= max_row; row++)
    // {
    //     for (int col = 0; col < n; col++)
    //     {
    //         cout << st[row][col] << " ";
    //     }
    //     cout << "\n";
    // }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        // l--;
        // r--;

        // find : 2^k <= (r-l+1)
        int p = log2(r - l + 1);
        // int k = (1 << p);
      
        int ans = 1e9;
        int len = r-l+1;
        // No overlap
        for(int i = p ; i >= 0 ; i--){
            if((1<<i) <= len){
                ans = min(ans , st[i][l]);
                len -= (1<<i);
                l += (1<<i);
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}