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

/*
    1. say all elements are 1, hence there sum = n(n+1)/2 and if k >= sum, answer is possible, otherwise -1.
    2. make all elements one except the last which will be : k-sum+1.
*/


void solve() {
  ll n;
  cin >> n;
  ll k;
  cin >> k;
    if(n==1){
        cout<<k<<endl;
        return ;
    }
  ll sum = n*(n+1)/2;
  if(k >= sum){
    rep2(i,0,n-1){
        cout<<1<<" ";
    }
    cout<<k-sum+1<<endl;
    return ;
  }
  else{
    cout<<-1<<endl;
    return ;
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
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
