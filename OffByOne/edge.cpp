#include <iostream>
#include <bitset>
using namespace std;
int main()
{
    int arr[3] = {3, 1, 5};
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += arr[i];
    }
    sum++;
    bitset<10> dp;
    dp[0] = 1;
    for (int i = 0; i < 3; i++)
    {
        dp = dp | (dp << arr[i]);
    }
    cout << (dp[2] == 1) << "\n";
    return 0;
}
{

    /*
    Using DP.
    Subset sum DP builds new sums by extending old sums,
    one element at a time, while preserving previous possibilities.
    */
    vector<int> a = {2, 3, 5, 1, 6};
    int MAXSUM = 17;

    vector<bool> dp(MAXSUM + 1, false);
    dp[0] = true;

    for (int x : a)
    {
        for (int s = MAXSUM; s >= x; s--)
        {
            dp[s] = dp[s] || dp[s - x];
        }
    }
}

/*
Uses bitset dp to determine, all the subsets sum possible.
How ?
1. Initially dp[0] = 1, why ? because we can create 0 by taking empty subset.
2. Now add 3, dp => {0} | {3} => {0,3} , then can be made.
3. Now add 1, dp => {0,3} | {1,4} => {0,3,1,4}. but why {1,4} => look, we can add 1 to 0 and 3 , which leads to 1 and 4.
   Thus we can create {0,1,3,4}, using the given elements till now.
4. Now add 5, dp => {0,1,3,4} | {5,6,8,9} => {0,1,3,4,5,6,8,9}
5. bitset dp has size equal to (sum of array + 1).
6. Each index determines, that we can create this sum.
*/