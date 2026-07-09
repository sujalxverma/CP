/*
* SAY WE HAVE AN ARRAY OF NUMBERS,
* AND FOR EACH INDEX I WANT TO FIND UPTILL RIGHMOST INDEX IT IS MINIMUM.
* AND SIMILARLY FOR LEFT SIDE AS WELL.
* O BASED INDEXING.
EG -> NUM =  [10, 20, 30, 50, 10, 70, 30]
    RIGHT =  [6,3,3,3,6,5,6]
    LEFT =   [0, 1, 2, 3, 0, 5, 5]

NOW, THIS CAN BE DONE USING STACK.
*/
/*
 * Say Stack<int>s, initially empty.
 * we insert index 0, means first element.
 * Now traverse from i = 1, to i = n-1
 * if a[i] > a[s.top()], means its possible that this number can be smaller from [t , n-1].
 * push in stack.
 * say at some point, index i, a[i] < a[s.top()], means index i-1 , was last index, upto which
 * a[s.top()] was smaller.
 * so we start to pop out. untill a[s.top()] <= a[i].
 */

// EG -> Max of min for every window size, from GeeksForGeeks.

#include "bits/stdc++.h"
using namespace std;
vector<int> maxOfMins(vector<int> &a)
{
    //  code here
    int n = (int)a.size();
    vector<int> left(n, 0);
    vector<int> right(n, n - 1);
    vector<vector<int>> dp(n, vector<int>(3)); // 0->left, 1->right
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = n - 1;
        dp[i][2] = a[i];
    }
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        int top = s.top();
        if (a[i] > a[top])
        {
            s.push(i);
        }
        else
        {
            while (!s.empty() && a[s.top()] > a[i])
            {
                right[s.top()] = i - 1;
                s.pop();
            }
            s.push(i);
        }
    }
    while (!s.empty())
    {
        s.pop();
    }
    s.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        int top = s.top();
        if (a[i] > a[top])
        {
            s.push(i);
        }
        else
        {
            while (!s.empty() && a[s.top()] > a[i])
            {
                left[s.top()] = i + 1;
                s.pop();
            }
            s.push(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        // 			std::cout << right[i] << " ";
        dp[i][1] = right[i];
    }
    // 		std::cout << "\n";
    for (int i = 0; i < n; i++)
    {
        // 			std::cout << left[i] << " ";
        dp[i][0] = left[i];
    }
    int mini = *min_element(begin(a), end(a));
    vector<int> ans(n, mini);
    vector<int> f(n + 1, 0);

    sort(dp.begin(), dp.end(), [](const vector<int> &a, const vector<int> &b)
         {
             return a[2] < b[2]; // sort by 3rd element (index 2)
         });

    for (int i = n - 1; i >= 0; i--)
    {
        int num = dp[i][2];
        int range = dp[i][1] - dp[i][0] + 1;

        if (f[range] == 1)
        {
            continue;
        }

        for (int r = range; r >= 1; r--)
        {
            if (f[r] == 1)
            {
                break;
            }
            f[r] = 1;
            ans[r - 1] = num;
        }
    }

    return ans;
}
