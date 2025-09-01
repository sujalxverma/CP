// // VERMA
// #include "bits/stdc++.h"
// using namespace std;
// typedef long long ll;
// typedef vector<int> vi;
// typedef vector<long long> vl;
// #define rep(i, a, b) for (int i = a; i < b; i++)
// #define rep2(i, a, b) for (long long i = a; i < b; i++)
// typedef unordered_map<int, int> umap;
// #define yes cout << "YES" << endl
// #define no cout << "NO" << endl
// #define even(a) (((a) % 2) == 0 ? 1 : 0)
// #define rev(v) reverse(v.begin(), v.end())
// #define sorting(v) sort(v.begin(), v.end())
// #define line cout << "\n"
// #define contains(vec, x) (std::find((vec).begin(), (vec).end(), (x)) != (vec).end())
// #define containsBS(vec, x) (std::binary_search((vec).begin(), (vec).end(), (x)))
// #define zerobits(x) __builtin_ctzll(x)
// #define setbits(x) __builtin_popcount(x)     // Count of set bits in int
// #define setbitsll(x) __builtin_popcountll(x) // Count of set bits in long long
// #define leadingzero(x) __builtin_clz(x)      // Leading zeros (int)
// #define trailingzero(x) __builtin_ctz(x)     // Trailing zeros (int)
// #define parity(x) __builtin_parity(x)        // 1 if odd number of set bits, else 0

// const int MOD = 1e9 + 7;
// const int INF = 1e9;
// const ll LINF = 1e18;

// inline bool prime(int num)
// {
//     if (num <= 1)
//         return false;
//     if (num == 2)
//         return true;
//     if (num % 2 == 0)
//         return false;
//     for (int i = 3; i * i <= num; i += 2)
//         if (num % i == 0)
//             return false;
//     return true;
// }
// inline int gcd(int a, int b)
// {
//     while (b != 0)
//     {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }

// inline int lcm(int a, int b)
// {
//     return a / gcd(a, b) * b;
// }

// #define ROTATE_VEC(v, k)                                 \
//     do                                                   \
//     {                                                    \
//         int __n = (int)(v).size();                       \
//         if (__n > 0)                                     \
//         {                                                \
//             int __k = (k) % __n;                         \
//             if (__k != 0)                                \
//             {                                            \
//                 reverse((v).begin(), (v).end());         \
//                 reverse((v).begin(), (v).begin() + __k); \
//                 reverse((v).begin() + __k, (v).end());   \
//             }                                            \
//         }                                                \
//     } while (0)

// inline int mod_add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
// inline int mod_sub(int a, int b) { return ((a % MOD) - (b % MOD) + MOD) % MOD; }
// inline int mod_mul(int a, int b) { return ((1LL * a % MOD) * (b % MOD)) % MOD; }
// inline int mod_pow(int base, int exp)
// {
//     int result = 1;
//     base %= MOD;
//     while (exp > 0)
//     {
//         if (exp % 2 == 1)
//             result = (1LL * result * base) % MOD;
//         base = (1LL * base * base) % MOD;
//         exp /= 2;
//     }
//     return result;
// }

// template <typename T>
// void printVector(const T &val)
// {
//     cerr << val;
// }

// template <typename T>
// void printVector(const vector<T> &v)
// {
//     cerr << "[ ";
//     for (const auto &elem : v)
//     {
//         printVector(elem);
//         cerr << " ";
//     }
//     cerr << "]";
// }
// #ifndef ONLINE_JUDGE
// #define debug(x)       \
//     cerr << #x << " "; \
//     printVector(x);    \
//     cerr << endl;
// #else
// #define debug(x)
// #endif

// //------------------------------------------------------------------------------------------------------------//
// //                                          Here you go

// void solve()
// {
//     string s;
//     cin >> s;

//     int left = 0; // receiver
//     int right = 0; // server
//     int pointleft = 0;
//     int pointright = 0;

//     bool turn = true; // true -> server , false -> reciever
//     int n = s.length();
//     for(int i = 0 ; i < n ; i++){
//         if(s[i] == 'S'){
//             pointright++;
//             if(pointright - pointleft >= 2 && pointright == 5){
//                 right++;
//                 pointright = 0;
//                 pointleft = 0;
//                 turn = true;
                
//             }else if(pointright == 10){
//                 right ++;
//                 pointright = 0;
//                 pointleft = 0;
//                 turn = true;
//             }
//         }else if(s[i] == 'R'){
//             pointleft++;
//             if(pointleft - pointright >= 2 && pointleft == 5){
//                 left++;
//                 pointleft = 0;
//                 pointright = 0;
//                  turn = false;
//             }else if(pointleft == 10){
//                 left ++;
//                 pointleft = 0;
//                 pointright = 0;
//                  turn = false;
//             }
//         }

//         if(s[i] == 'Q') {
            
//             if(left == 2){
//                 cout<<left<<" (winner)"<<" - "<<right<<"\n";

//             }
//             else if(right == 2){
//                  cout<<left<<" - "<<right<<" (winner)\n";
//             }

//             else if(turn == true){
//                cout<<left<<" "<<"("<<pointleft<<")"<<" - "<<right<<" ("<<pointright<<"*)\n";
//             }else{
//                  cout<<left<<" "<<"("<<pointleft<<"*)"<<" - "<<right<<" ("<<pointright<<")\n";
//             }

//         }


//     }

// }

// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("Error.txt", "w", stderr);
// #endif

//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     ll t = 1;
//     // cin >> t;
//     while (t--)
//     {
//         solve();
//     }
// }


#include "bits/stdc++.h"
using namespace std;

int main()
{

    string s;
    getline(cin, s);

    int lg = 0;
    int rg = 0;
    int lp = 0;
    int rp = 0;
    bool ls = true;
    bool end = false;

    for (char c : s)
    {
        // if (end)
        // {
        //     if (c == 'Q')
        //     {
        //         cout << lg << " - " << rg << " (winner)" << endl;
        //     }
        //     continue;
        // }

        if (c == 'S')
        {
            if (ls)
                lp++;
            else
                rp++;
        }
        else if (c == 'R')
        {
            if (ls)
            {
                rp++;
                ls = false;
            }
            else
            {
                lp++;
                ls = true;
            }
        }
        else if (c == 'Q')
        {
            if (rg == 2)
            {
                end = true;
                cout << lg << " - " << rg << " (winner)" << endl;
            }
            else if(lg==2){
                end = true;
                cout << lg<<" (winner)"  << " - " << rg << "\n"<< endl;
            }
      
            else
            {
                if (ls)
                {
                    cout << lg << " (" << lp << "*) - " << rg << " (" << rp << ")" << endl;
                }
                else
                {
                    cout << lg << " (" << lp << ") - " << rg << " (" << rp << "*)" << endl;
                }
            }
            continue;
        }

        bool oend = false;
        if (lp >= 5 && lp - rp >= 2)
        {
            lg++;
            oend = true;
        }
        else if (rp >= 5 && rp - lp >= 2)
        {
            rg++;
            oend = true;
        }
        else if (lp == 10)
        {
            lg++;
            oend = true;
        }
        else if (rp == 10)
        {
            rg++;
            oend = true;
        }

        if (oend)
        {
            lp = 0;
            rp = 0;
            if (lg > 0 && rg < lg)
            {
                ls = true;
            }
            else if (rg > lg)
            {
                ls = false;
            }
            if (lg == 2 || rg == 2)
            {
                end = true;
            }
        }
    }

    return 0;
}