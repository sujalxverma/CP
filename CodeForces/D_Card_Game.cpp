#include "bits/stdc++.h"
using namespace std;

int n;
char trump;
int t;
map<char, int> value = {
    {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}};

void solve()
{
    cin >> n >> trump;
    vector<string> arr(2 * n);
    map<char, vector<char>> mp;

    for (int i = 0; i < 2 * n; i++)
    {
        cin >> arr[i];
        mp[arr[i][1]].push_back(arr[i][0]);
    }

    // Sort each suit by rank
    for (auto &s : mp)
        sort(s.second.begin(), s.second.end(), [&](char a, char b)
             { return value[a] < value[b]; });

    vector<string> result;
    vector<string> leftovers;
    vector<string> trumps;

    // Pair same-suit cards first
    for (auto &s : mp)
    {
        if (s.first == trump)
            continue;

        for (int i = 0; i + 1 < (int)s.second.size(); i += 2)
        {
            string c1 = string(1, s.second[i]) + s.first;
            string c2 = string(1, s.second[i + 1]) + s.first;
            result.push_back(c1 + " " + c2);
        }

        // if an odd card remains, mark as leftover
        if (s.second.size() % 2 == 1)
        {
            leftovers.push_back(string(1, s.second.back()) + s.first);
        }
    }

    // Collect trump cards
    for (char c : mp[trump])
        trumps.push_back(string(1, c) + trump);

    // Now use trumps to pair leftovers
    if (trumps.size() < leftovers.size())
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (int i = 0; i < leftovers.size(); i++)
    {
        result.push_back(leftovers[i] + " " + trumps.back());
        trumps.pop_back();
    }

      
    if (trumps.size() % 2 == 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
        // Pair remaining trumps among themselves
    for (int i = 0; i + 1 < trumps.size(); i += 2)
    {
        result.push_back(trumps[i] + " " + trumps[i + 1]);
    }

    // Output final pairs
    for (string s : result)
        cout << s << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--)
        solve();
    return 0;
}
