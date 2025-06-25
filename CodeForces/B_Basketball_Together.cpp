#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rep2(i, a, b) for (long long i = a; i < b; i++)
typedef unordered_map<int, int> umap;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define even(a) (((a) % 2) == 0 ? 1 : 0)
#define rev(v) reverse(v.begin(), v.end())
#define gcd(a, b) ([](int x, int y) {while (y != 0) { int temp = y;y = x % y; x = temp;}return x; })(a, b)
#define lcm(a, b) (a * b / gcd(a, b))
#define sorting(v) sort(v.begin(), v.end())
#define line cout << endl
#define contains(vec, x) (std::find((vec).begin(), (vec).end(), (x)) != (vec).end())
#define containsBS(vec, x) (std::binary_search((vec).begin(), (vec).end(), (x)))
inline bool prime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (int i = 3; i * i <= num; i += 2)
        if (num % i == 0)
            return false;
    return true;
}
#define ROTATE_VEC(v, k)                                 \
    do                                                   \
    {                                                    \
        int __n = (int)(v).size();                       \
        if (__n > 0)                                     \
        {                                                \
            int __k = (k) % __n;                         \
            if (__k != 0)                                \
            {                                            \
                reverse((v).begin(), (v).end());         \
                reverse((v).begin(), (v).begin() + __k); \
                reverse((v).begin() + __k, (v).end());   \
            }                                            \
        }                                                \
    } while (0)

const int MOD = 100000;

template <typename T>
void printVector(const T &val)
{
    cerr << val;
}

template <typename T>
void printVector(const vector<T> &v)
{
    cerr << "[ ";
    for (const auto &elem : v)
    {
        printVector(elem);
        cerr << " ";
    }
    cerr << "]";
}
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    printVector(x);    \
    cerr << endl;
#else
#define debug(x)
#endif

//------------------------------------------------------------------------------------------------------------//
//                                          Here you go

/*
    We will start with with sorted order, by selecting the biggest numbers and coming down at each iteration, as we can replace team memebers
    power by this biggest number, so we can calculate how many players in that team are required, then we will select those, 
    say k, weakest players from starting because it is sorted.
*/
/*
    Approach:

    - First, we sort the array of player strengths in ascending order.
    - We start from the strongest player (end of the array) and move backwards.
    - At each iteration, we try to form a valid team using the current player's strength
      as the team's "effective" strength (since we’re allowed to treat all players in
      the team as having this strength).
    
    - To meet the requirement (e.g., total strength ≥ d + 1), we calculate how many players 
      (k) are needed: k = ceil((d + 1) / current_strength).
      
    - If we still have at least k players left (from the remaining unassigned ones), 
      we form a team, increment our team count, and update the number of players used.

    - This way, we always try to use the strongest players to minimize team size
      and maximize the number of valid teams.
*/

void solve() {
    ll n, d;
    cin >> n >> d;
    vl a(n);
    rep2(i, 0, n) {
        cin >> a[i];
    }

    // Sort in ascending order
    sort(a.begin(), a.end());

    ll count = 0;
    ll used = 0;

    for (ll i = n - 1; i >= 0; --i) {
        // How many players are needed with this strength?
        ll players = ceil((d + 1) / double(a[i]));

        // Check if we have enough players left to form a group
        if (used + players <= n) {
            count++;
            used += players;
        } else {
            break; // Not enough players left
        }
    }

    cout << count << endl;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // ll t;
    // cin >> t;
    // while (t--)
    // {
        solve();
    // }
}
