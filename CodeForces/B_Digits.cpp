#include <iostream>
#include <vector>
using namespace std;
/*
This program checks which of the numbers {1, 3, 5, 7, 9} divide a number N,
where N consists of a single digit 'd' repeated n! (n factorial) times.

Key ideas:
- A number made of digit 'd' repeated k times has digit sum d * k.
- For large n, n! quickly grows very large, but divisibility patterns stabilize for n >= 7.

Divisibility checks:
1. 1: All numbers are divisible by 1.
2. 3: Number is divisible by 3 if d * k is divisible by 3.
3. 5: Number is divisible by 5 if d is 0 or 5.
4. 7: Known mathematical property—
      If n >= 3, the repeated-digit number will always be divisible by 7 due to cyclic patterns in base 10.
      Otherwise, check if d is divisible by 7.
5. 9: Number is divisible by 9 if d * k is divisible by 9.

Practical optimization:
Since the result is stable for n >= 7, we set n = min(n, 7).
Compute k = n!, and use it only for rules that require it.

The function then prints all divisors that pass the test for the given (n, d).

*/
void solve()
{
    long long n, d;
    cin >> n >> d;

    // For divisibility, n does not need to be more than 7
    n = min(n, 7LL);

    long long fact = 1;
    for (int i = 1; i <= n; ++i)
        fact *= i;

    vector<int> ans;
    ans.push_back(1); // 1 divides all

    // Divisibility by 3: sum of digits is d * fact
    if ((d * fact) % 3 == 0)
        ans.push_back(3);

    // Divisibility by 5: last digit is 0 or 5
    if (d == 0 || d == 5)
        ans.push_back(5);

    // Divisibility by 7
    if (n >= 3 || d % 7 == 0)
        ans.push_back(7);

    // Divisibility by 9
    if ((d * fact) % 9 == 0)
        ans.push_back(9);

    for (size_t i = 0; i < ans.size(); ++i)
    {
        cout << ans[i];
        if (i + 1 < ans.size())
            cout << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
