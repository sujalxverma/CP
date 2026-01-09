#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long r, c;
    cin >> r >> c;

    if (r == c && r == 1)
    {
        cout << 0 << "\n";
        return 0;
    }
    if(c == 1){
        int start = 2;
        for(int i = 0 ; i < r ; i++){
            cout<<start<<"\n";
            start++;
        }
        return 0;
    }
    vector<vector<long long>> ans(r, vector<long long>(c));
    // traverse column wise.
    int start = r + 1;
    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < r; i++)
        {
            ans[i][j] = 1LL * start * (i + 1);
        }
        start++;
    }

    for (int j = 0; j < r; j++)
    {
        for (int i = 0; i < c; i++)
        {
            cout << ans[j][i] << " ";
        }
        cout << "\n";
    }

    return 0;
}