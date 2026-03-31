#include <iostream>
using namespace std;
/*
-Binary Exponentitation, finds the aˣ in log(x) time.
-Can be converted to modular exponentiation by using MOD.
-Time Complexity : O(log(x))
-Space Complexity : O(1)
*/
int binaryExpo(int n, int exp)
{
    int res = 1;
    while (exp > 0)
    {
        if (exp & 1)
            res = (res * n);
        n = (n * n);
        exp >>= 1;
    }
    return res;
}