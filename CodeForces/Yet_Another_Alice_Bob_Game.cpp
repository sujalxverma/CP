#include "bits/stdc++.h"
using namespace std;

// Why a + 1 is important

// Consider any pile of size a + 1:

// Alice removes x stones, where 1 ≤ x ≤ a

// Stones left = (a + 1) - x

// Bob can now remove exactly x stones

// Stones left = 0

// So whoever starts with exactly a + 1 stones will lose, because the second player can always mirror the move.

// Thus:

// n = a + 1 → losing position

// n = 2(a + 1) → losing

// n = 3(a + 1) → losing

// …

// These are called P-positions (previous player wins).


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        if (n <= a)
        {
            cout << "Alice\n";
        }
        else if (a > 1 && b == 1)
        {
            cout << "Alice\n";
        }
        else if (a == 1 && b > 1)
        {
            if (n == 1)
            {
                cout << "Alicen\n";
            }
            else
            {
                cout << "Bob\n";
            }
        }
        else if (a == 1 && b == 1)
        {
            if (n % 2 == 0)
            {
                cout << "Bob\n";
            }
            else
            {
                cout << "Alice\n";
            }
        }
        else if (a > 1 && b > 1)
        {
            if (a > b)
            {
                cout << "Alice\n";
            }
            else if (b > a)
            {

                cout << "Bob\n";
            }
            else
            {
                // when both are eqaual.
                if (n - 1 == b)
                {
                    cout << "Bob\n";
                }
                else if (n % (a + 1) == 0)
                    cout << "Bob" << endl;
                else
                    cout << "Alice" << endl;
            }
        }
    }
    return 0;
}

