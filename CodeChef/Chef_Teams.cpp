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
const int MOD = 1e7 + 7;

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

// void solve()
// {
//     int n;
//     cin >> n;
//     ll order = 1;
//     vector<tuple<ll, ll, ll>> chefs(n + 1); // 1 based indexing.
//     rep(i, 1, n + 1)
//     {
//         ll a, b;
//         cin >> a >> b;
//         chefs[i] = {a, b, order};
//         order++;
//     }
//     sort(chefs.begin() + 1, chefs.end()); // begins sorting from 1 index.
//     vector<tuple<ll, ll, ll>> young;
//     vector<tuple<ll, ll, ll>> old;

//     int mid = (n + 1) / 2;
//     for (int i = 1; i <= mid; i++)
//         young.push_back(chefs[i]);
//     for (int i = mid + 1; i <= n; i++)
//         old.push_back(chefs[i]);

//     int i = 1;
//     int j = 1;
//     ll youngSum = 0;
//     ll oldSum = 0;
//     int count = 1;

//     sort(young.begin(), young.end(), [](const auto &a, const auto &b)
//          {
//              return get<2>(a) < get<2>(b); // sort by third element
//          });

//     sort(old.begin(), old.end(), [](const auto &a, const auto &b)
//          {
//              return get<2>(a) < get<2>(b); // sort by third element
//          });

//     while (i <= young.size() && old.size())
//     {
//         auto [a1, r1, o1] = young[i];
//         auto [a2, r2, o2] = old[j];

//         if (o1 == count)
//         {
//             youngSum += r1;
//             cout << abs(youngSum - oldSum) << endl;
//             i++;
//             count++;
//         }
//         else
//         {
//             oldSum += r2;
//             cout << abs(youngSum - oldSum) << endl;
//             j++;
//             count++;
//         }
//     }
//     if (i <= young.size())
//     {
//         auto [a1, r1, o1] = young[i];
//         youngSum += r1;
//         cout << abs(youngSum - oldSum) << endl;
//         i++;
//     }
//     if (j <= old.size())
//     {
//         auto [a2, r2, o2] = old[j];
//         oldSum += r2;
//         cout << abs(youngSum - oldSum) << endl;
//         j++;
//     }
// }

void solve()
{
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> old;
    priority_queue<pair<int, int>> young;
    old.push({INT_MAX, 0});
    young.push({INT_MIN, 0});
    // {age , rating}
    ll youngRating = 0, oldRating = 0;

    rep(i, 0, n)
    {
        ll age, rating;
        cin >> age >> rating;
        /*
           1. If i is odd, and the new chef is younger than the youngest old chef, then it means he can joing YOUNG chef team.
           2. But if youngest old chef is younger than the new chef, then it means youngest old chef joing YOUNG chef team.
              and new chef joins the old chef team.
            3. If i is odd , check the conditions for old chefs.

        */
        if (!(i % 2))
        {

            auto minOld = old.top();
            if (minOld.first < age)
            {
                old.pop();
                young.push(minOld);
                youngRating += minOld.second;
                old.push({age, rating});
                oldRating = oldRating - minOld.second + rating;
            }
            else
            {
                young.push({age, rating});
                youngRating += rating;
            }
        }

        /*
          1. If i is even, and the new chef is younger than the oldest young chef, then it means he can joing YOUNG chef team and oldest young chef
             joing OLD team.
          2. But if oldest young chef is older than the new chef, then it means oldest young chef joing OLD chef team.
             and new chef joins the YOUNG chef team.
           3. If i is evdn , check the conditions for young chefs.

       */

        else
        {
            auto maxYoung = young.top();
            if (maxYoung.first > age)
            {
                young.pop();
                old.push(maxYoung);
                oldRating += maxYoung.second;
                young.push({age, rating});
                youngRating = youngRating - maxYoung.second + rating;
            }
            else
            {
                old.push({age, rating});
                oldRating += rating;
            }
        }

        cout << abs(youngRating - oldRating) << endl;
    }
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
