#include "bits/stdc++.h"
using namespace std;
vector<int> a;

/*
1. I understand the solution.
2. If we either maximise P or inv(P) , then maximising one of them will make the other one 0, either all
    ascends (increasing) or all are descends (decreasing).
3. So, we divide it into blocks of size ~sqrt(N).
4. So within each block value is increasing in P, and when inv(P) is created, then within each block values
   are decreasing.
5. Also in P, previous blocks will have larger values than corresponding values of current block.
6. So, when creating inverse of this P, larger values will be at lower index, and larger values will be at larger index.
7. Thus we have descends as well.
8. Take example.
9. N = 9.
10. P (blocks) -> [3,6,9] , [2,5,8] , [1,4,7]  -> ascends : 6
11. inv(P) (blocks) -> [7,4,1] , [8,5,2] , [9,6,3] -> descends : 6
12. Now in each block in P, values are increasing.
13. And each block in inv(P), values are decreasing.
14. Thus if some values remain then simply make an extra block and append them as in their natural order.
15. Example : N = 1.
16. P (blocks) -> [3,6,9] , [2,5,8] , [1,4,7] , [10,11]
17. Thus making optimal solution.
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    a.resize(n);
    int s = floor(sqrt(n));
    // blocks of size s, and each block has size s.
    // pattern : [B,2B,3B..],[B-1,2B-1,3B-1...],[B-2,2B-2,3B-2...],....,[1,B+1,2B+1...]
    int start = 0; // block
    for (int i = 1; i <= s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            cout << (j + 1) * s - start << " ";
        }
        start++;
    }
    if (s * s != n)
    {
        for (int i = s * s; i < n; i++)
        {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
    return 0;
}