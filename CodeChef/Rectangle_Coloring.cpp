#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll cost(vector<ll> sides, vector<ll> colors)
{

    ll cost_value = 0;
    int i = 0;
    int j = 0;
    while (i < 4 && j < 3)
    {
        if (colors[j] >= sides[i])
        {
            cost_value++;
            colors[j] -= sides[i];
            i++;
            if (colors[j] == 0)
            {
                j++;
            }
            // j remains same.
        }
        else
        {
            cost_value++;
            sides[i] -= colors[j];
            colors[j] = 0;

            j++;
            // i remains same.
        }
    }
    return cost_value;
}

void solve()
{
    ll l, w, r, g, b;
    cin >> l >> w >> r >> g >> b;
    vector<ll> colors = {r, g, b};
    vector<ll> rect_sides = {l, l, w, w};
    vector<vector<ll>> subsets; // get all permutation of colors.
    vector<vector<ll>> sides;

    sort(begin(colors), end(colors));
    sort(begin(rect_sides), end(rect_sides));

    do
    {
        subsets.push_back(colors);
    } while (next_permutation(colors.begin(), end(colors)));
    do
    {
        sides.push_back(rect_sides);
    } while (next_permutation(rect_sides.begin(), end(rect_sides)));

    ll ans = 1e18;

    for (int i = 0; i < (int)subsets.size(); i++)
    {
        for (int j = 0; j < (int)sides.size(); j++)
        {
            ans = min(ans, cost(sides[j], subsets[i]));
        }
    }
    cout << ans << "\n";
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