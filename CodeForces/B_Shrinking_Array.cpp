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

// Problem Logic:
// 1. If any two adjacent elements differ by ≤ 1, output 0 (already almost sorted).
// 2. Otherwise, check for a triplet where the third element lies between the first two —
//    this suggests a local pattern that can be fixed with a single operation → output 1.
// 3. If no such pattern is found, output -1 (requires more than one fix or not possible).
// Use case: Detecting if an array can be fixed with minimal operations (greedy/constructive).


void solve()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    rep(i,1,n){
        if(abs(a[i]-a[i-1])<= 1){
            cout<<0<<endl;
            return ;
        }
    }

    bool flag = false;
    rep(i, 1, n - 1)
    {
        int mini = min(a[i], a[i - 1]);
        int maxi = max(a[i], a[i - 1]);
        if (a[i + 1] >= mini && a[i + 1] <= maxi)
        {
            flag = true;
            cout << 1 << endl;
            return;
        }
    }
    for (int i = n - 2; i > 0; i--)
    {
        int mini = min(a[i], a[i + 1]);
        int maxi = max(a[i], a[i + 1]);
        if (a[i - 1] >= mini && a[i - 1] <= maxi)
        {
            flag = true;
            cout << 1 << endl;
            return;
        }
    }

    if(!flag){
        cout<<-1<<endl;
    }
}

// CF
// void solve() {
// 	int n; cin >> n;
// 	vector<int> v(n);
// 	for(auto &x : v)cin >> x;
// 	for(int i = 0; i  < n - 1; ++i){
// 		if(abs(v[i] - v[i + 1]) <= 1) {
// 			cout << 0 << '\n';
// 			return;
// 		}
// 	}
// 	for(int i = 1; i < n - 1; ++i){
// 		if((v[i] > v[i + 1]) != (v[0] > v[1])) {
// 			cout << 1 << '\n';
// 			return;
// 		}
// 	}
// 	cout << -1 << '\n';
// }
int main()
{

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
