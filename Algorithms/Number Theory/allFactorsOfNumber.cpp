#include <iostream>
#include <vector>
using namespace std;
/*
-All factors of a number including 1 and itself.
*/
vector<int> factors(int n)
{
    vector<int> f;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            f.push_back(i);
            if (n / i != i)
            {
                f.push_back(n / i);
            }
        }
    }
    return f;
}