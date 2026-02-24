/*
-- The use of namespace.
When we have multiple functions of same name in different files,
Then compiler find it difficult to understand which function to use.
Thus we can use namespace. 
We can create function in different files. and include them in header.
And can use : using namespace "NAME_OF_NAMESPACE_IN_THE_FILE";

*/



#include "bits/stdc++.h"
using namespace std;

namespace FIRST_FUN
{
    void print()
    {

        cout << "This is first function\n";
    }
}

namespace SECOND_FUN
{
    void print()
    {

        cout << "This is second function\n";
    }

}
using namespace SECOND_FUN;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    FIRST_FUN::print();
    print();
    return 0;
}