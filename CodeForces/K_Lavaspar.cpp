// VERMA
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
#define sorting(v) sort(v.begin(), v.end())
#define line cout << "\n"
#define contains(vec, x) (std::find((vec).begin(), (vec).end(), (x)) != (vec).end())
#define containsBS(vec, x) (std::binary_search((vec).begin(), (vec).end(), (x)))
#define zerobits(x) __builtin_ctzll(x)
#define setbits(x) __builtin_popcount(x)     // Count of set bits in int
#define setbitsll(x) __builtin_popcountll(x) // Count of set bits in long long
#define leadingzero(x) __builtin_clz(x)      // Leading zeros (int)
#define trailingzero(x) __builtin_ctz(x)     // Trailing zeros (int)
#define parity(x) __builtin_parity(x)        // 1 if odd number of set bits, else 0

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

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
inline int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

inline int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
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

inline int mod_add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
inline int mod_sub(int a, int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
inline int mod_mul(int a, int b) { return ((1LL * a % MOD) * (b % MOD)) % MOD; }
inline int mod_pow(int base, int exp)
{
    int result = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (1LL * result * base) % MOD;
        base = (1LL * base * base) % MOD;
        exp /= 2;
    }
    return result;
}

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
    Approach Explanation:

    1. The code reads the grid dimensions (L rows, C columns) and the grid data. It also reads n words.
    2. For each word, it stores both the original and a sorted version (for anagram checking).
    3. It initializes a contribution matrix, where each cell maintains a set of indices of words for which it contributes (via an anagram match of that word in some direction through that cell).
    4. For every word and each possible direction (right, down, diagonal, anti-diagonal), it checks every possible starting cell.
       - For each position, it extracts a sequence of characters of the same length as the current word, sorts the sequence, and checks for equality with the sorted word.
       - On a match, it marks every cell along the matching sequence as contributing to that word by inserting its index into the corresponding set.
    5. After processing all words, grid cells contributing to at least two words (having size of set ≥ 2) are counted as "specialWords".
    6. The program outputs this count of special cells.

    Complexity:
    - The algorithm is efficient due to fixed directions (only 4) and uses set operations to avoid double-counting contributions per cell.
    - For each word, all possible placements in the grid are evaluated, making the worst-case time O(n * L * C * len * 4) where 'len' is the average word length.

    Notes:
    - Uses sorted strings to detect anagrams.
    - Contributions are tracked via sets to handle overlap efficiently.
    - The result reflects high-overlap regions in the grid.
*/

void solve()
{
    int L, C;
    cin >> L >> C;
    vector<string> grid(L);
    for (int i = 0; i < L; i++)
        cin >> grid[i];
    int n;
    cin >> n;
    vector<string> words(n);
    vector<string> sortedWords(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
        sortedWords[i] = words[i];
        sort(sortedWords[i].begin(), sortedWords[i].end());
    }

    vector<vector<set<int>>> contribution(L, vector<set<int>>(C));

    vector<pair<int, int>> direction = {
        {0, 1}, {1, 0}, {1, 1}, {1, -1}};
    for (int i = 0; i < n; i++)
    {
        string sortWord = sortedWords[i];
        int len = sortWord.size();
        for (int dir = 0; dir < 4; dir++)
        {
            int dx = direction[dir].first;
            int dy = direction[dir].second;
            for (int x = 0; x < L; x++)
            {
                for (int y = 0; y < C; y++)
                {
                    int newX = x + (len - 1) * dx;
                    int newY = y + (len - 1) * dy;
                    if (newX < 0 || newX >= L || newY < 0 || newY >= C)
                        continue;
                    string sequence = "";
                    int X = x, Y = y;
                    for (int k = 0; k < len; k++)
                    {
                        sequence.push_back(grid[X][Y]);
                        X += dx;
                        Y += dy;
                    }
                    string sortedSequence = sequence;
                    sort(sortedSequence.begin(), sortedSequence.end());
                    if (sortWord == sortedSequence)
                    {
                        X = x;
                        Y = y;
                        for (int k = 0; k < len; k++)
                        {
                            contribution[X][Y].insert(i);
                            X += dx;
                            Y += dy;
                        }
                    }
                }
            }
        }
    }
    int specialWords = 0;
    for (int x = 0; x < L; x++)
        for (int y = 0; y < C; y++)
            if (contribution[x][y].size() >= 2)
                specialWords++;
    cout << specialWords << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
