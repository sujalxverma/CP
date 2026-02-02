#include "bits/stdc++.h"
using namespace std;

/*
1. We can check for all substrings of length k, which are factors of n.
2. But why ? b/c k*(n/k) is n, means k can be repeated (n/k) times.
4. considering prefix substring of arbitary length k, and check if it satisfies the condition, diff <= 1.
5. But this fails, for s -> hshahahaha
6. But after selecting prefix, we can repeat the same for suffix, just by repeating the string s, and doing
   the same procedure.
7. I am not sure, why it worked ?
8. I somehow know its going to work, but intuition is not, i come up with.
*/

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> f(26, 0);
    for (int i = 0; i < n; i++)
    {
        f[s[i] - 'a']++;
    }
    // check if all characters are same.
    for (int i = 0; i < 26; i++)
    {
        if (f[i] == n)
        {
            cout << "1\n";
            return;
        }
    }
    int mini = 1e9;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            for (int k : {i, n / i})
            {
                if (k == n)
                    continue; // optional, n is default fallback

                string a = s.substr(0, k);
                int diff = 0;
                for (int j = 0; j < n; j++)
                {
                    if (s[j] != a[j % k])
                        diff++;
                }

                if (diff <= 1)
                {
                    // cout << k << "\n";
                    mini = min(mini, k);
                    // return;
                }
            }
        }
    }
    reverse(s.begin(), s.end());
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            for (int k : {i, n / i})
            {
                if (k == n)
                    continue; // optional, n is default fallback

                string a = s.substr(0, k);
                int diff = 0;
                for (int j = 0; j < n; j++)
                {
                    if (s[j] != a[j % k])
                        diff++;
                }

                if (diff <= 1)
                {
                    // cout << k << "\n";
                    mini = min(mini, k);
                    // return;
                }
            }
        }
    }
    if (mini == 1e9)
    {
        cout << n << "\n";
        return;
    }
    cout << mini << "\n";
    return;
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