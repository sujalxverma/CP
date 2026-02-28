#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

/* 
bruteforce
bool isRBS(const string &s)
{
    int balance = 0;
    for (char c : s)
    {
        if (c == '(')
        {
            balance++;
        }
        else
        { // ')'
            balance--;
        }

        if (balance < 0)
        {
            return false; // more ')' than '(' at some prefix
        }
    }
    return balance == 0; // must end perfectly balanced
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<string> st;
    for (int i = 0; i < (1 << n); i++)
    {
        string r = "";
        for (int j = 0; j < n; j++)
        {
            if ((1 << j) & i)
            {
                r = r + s[j];
            }
        }
        if (r.length() == 0)
            continue;
        st.push_back(r);
    }

    vector<string> res;
    for (int i = 0; i < (int)st.size(); i++)
    {
        if (isRBS(st[i]))
        {
            res.push_back(st[i]);
        }
    }

    int ans = -1;
    for (auto &x : res)
    {
        int i = 0;
        int j = 0;
        while (i < x.length() && j < n)
        {
            if (x[i] != s[j])
            {
                // if characters differ as per condition, then update ans.
                if (x[i] == '(' && s[j] == ')')
                {
                    ans = max(ans, (int)x.length());
                }

                break;
            }
            i++;
            j++;
        }
    }

    cout << ans << "\n";
}
*/

void solve(){
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = high_resolution_clock::now();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}