#include <iostream>
#include <vector>
using namespace std;
/*
-Calculates all prime factors of number.
-Time Complexity : O(√n)
-Space Complexity : O(k), where k is distinct prime factors.

*/
vector<int> primeFactors(int n)
{
    vector<int> f;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            f.push_back(i);
            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }
    if (n > 1)
    {
        f.push_back(n);
    }
    return f;
}