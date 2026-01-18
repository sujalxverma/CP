#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int neutral = 0;
vector<ll> a;
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
    vector<vector<ll>> sparse_table(max_row + 1, vector<ll>(n, neutral));

    sparse_table[0] = a;

    for (int row = 1; row <= max_row; row++)
    {
        for (int col = 0; col + (1 << row) <= n; col++)
        {
            sparse_table[row][col] = sparse_table[row - 1][col] + sparse_table[row - 1][col + (1 << (row - 1))];
        }
    }

    while (q--)
    {
        int start, end;
        cin >> start >> end;
        start--;
        end--;
        ll sum_of_range = 0;
        int range = end - start + 1;
        int max_power_of_2 = log2(range);

        // No Overlap.
        for (int row = max_power_of_2; row >= 0; row--)
        {
            if ((1 << row) <= range)
            {
                sum_of_range += sparse_table[row][start];
                // update start
                start += (1 << row);
                // update range, (remaining range)
                range -= (1 << row);
            }
        }
        cout << sum_of_range << "\n";
    }

    return 0;
}