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
#define line cout << "\n";
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

pair<ll,ll>searchFloor(ll floor,vector<ll>&cummulative){
    ll s = 0;
    ll e = cummulative.size()-1;
    while(s<=e){
        ll mid = s+(e-s)/2;
        ll upper = cummulative[mid];
        ll lower = (mid == 0) ? 1 : cummulative[mid - 1] + 1;
        if(floor >= lower && floor <= upper){
            return {mid+1,floor-lower+1};
        }
        else if(floor > upper){
            s = mid+1;
        }
        else{
            e = mid-1;
        }

    }
    return {-1,-1};
}

void solve()
{
   ll n,m;
   cin >> n >> m;
   vl a(n);
   // floors in building
   rep2(i,0,n){
    cin >> a[i];
   }
   // letters
   vl b(m);
   rep2(i,0,m){
    cin >> b[i];
   }
   vl cummulative(n);
   cummulative[0] = a[0];
   rep2(i,1,n){
        cummulative[i] = cummulative[i-1] + a[i];
   }

   rep2(i,0,m){
    pair<ll,ll>ans = searchFloor(b[i],cummulative);
    cout<<ans.first<<" "<<ans.second<<"\n";
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
