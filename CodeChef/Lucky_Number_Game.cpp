#include "bits/stdc++.h"
using namespace std;

void solve()
{

    /*
    If Bob has countA elements divisible by his lucky number a, he can remove all of them immediately in his first move
    and win — if he wants to.
    Similarly for Alice.*/
    int n, a, b;
    cin >> n >> a >> b;
    int arr[n], alice = 0, bob = 0, albob = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % a == 0 && arr[i] % b == 0)
        {
            albob++;
        }
        else if (arr[i] % a == 0)
        {
            bob++;
        }
        else if (arr[i] % b == 0)
        {
            alice++;
        }
    }
    // if(alice == 0 && bob == 0 && albob != 0) {
    //     cout << "BOB" << endl;
    // }
    if (alice == 0 && bob == 0 && albob != 0)
    {
        if (albob % 2 == 0)
            cout << "ALICE" << endl;
        else
            cout << "BOB" << endl;
        return;
    }
    else if (alice == 0 && bob == 0 && albob == 0)
    {
        cout << "ALICE" << endl;
    }
    else if (albob == 0)
    {
        if (alice >= bob)
        {
            cout << "ALICE" << endl;
        }
        else
        {
            cout << "BOB" << endl;
        }
    }
    else
    {
        if (alice > bob)
        {
            cout << "ALICE" << endl;
        }
        else
        {
            cout << "BOB" << endl;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}