




#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
#define rep(i,a,b) for(ll i = a; i < b; i++)
#define rep2(i,a,b) for(ll i = a; i <= b; i++)
#define line cout << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<vl> val(3, vl(n + 1, 0));  // values 
        vector<vl> pf(3, vl(n + 1, 0));  // prefix

        rep(i, 0, 3) {
            rep2(j, 1, n) {
                cin >> val[i][j];
                pf[i][j] = pf[i][j - 1] + val[i][j];
            }
        }

        bool ok = false;
        vi perm = {0, 1, 2};
        ll comp = (pf[perm[0]][n] + 2) / 3;

        do {
            ll cur = 1;
            while(cur <= n && pf[perm[0]][cur] < comp) cur++;
            if(cur > n) continue;

            for(ll j = cur + 1; j < n; j++) {
                if(pf[perm[1]][j] - pf[perm[1]][cur] >= comp && pf[perm[2]][n] - pf[perm[2]][j] >= comp) {
                    // Store answer intervals according to perm order
                    vpll ans(3);
                    ans[perm[0]] = {1, cur};
                    ans[perm[1]] = {cur + 1, j};
                    ans[perm[2]] = {j + 1, n};

                    rep(i, 0, 3) {
                        cout << ans[i].first << " " << ans[i].second << " ";
                    }
                    line;
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        } while(next_permutation(perm.begin(), perm.end()));

        if(!ok) cout << -1 << endl;
    }
    return 0;
}


// This code leads to TLE
// //------------------------------------------------------------------------------------------------------------//
// //                                          Here you go

// bool partition(const vector<ll> &pa, const vector<ll> &pb, const vector<ll> &pc, ll n, ll atleast,int check)
// {
//     for (ll i = 1; i <= n; ++i)
//     {
//         if (pa[i] < atleast)
//             continue;

//         for (ll j = i + 1; j <= n; ++j)
//         {
//             if (pb[j] - pb[i] < atleast)
//                 continue;

//             // Binary search for k in [j+1, n] such that pc[k] - pc[j] >= atleast
//             ll left = j + 1, right = n, ans = -1;
//             while (left <= right)
//             {
//                 ll mid = (left + right) / 2;
//                 if (pc[mid] - pc[j] >= atleast)
//                 {
//                     ans = mid;
//                     right = mid - 1;
//                 }
//                 else
//                 {
//                     left = mid + 1;
//                 }
//             }
//             if (ans != -1)
//             {
//                 // a,b,c
//                 if(check == 1){
//                     // cout<<check<<endl;
//                     cout << 1 << " " << i << " " << i + 1 << " " << j << " " << j + 1 << " " << ans << endl;
//                      return true;
//                 }
//                 // a,c,b
//                  if(check == 2){
//                     //   cout<<check<<endl;
//                     cout << 1 << " " << i << " " << j + 1 << " " << n << " " << i + 1 << " " << j << endl;
//                      return true;
//                 }
//                 // b,a,c
//                  if(check == 3){
//                     //   cout<<check<<endl;
//                     cout << i+1 << " " << j << " " << 1 << " " << i << " " << j + 1 << " " << n << endl;
//                      return true;
//                 }
//                 // b c a
//                  if(check == 4){
//                     //   cout<<check<<endl;
//                     cout << j+1 << " " << n << " " << 1 << " " << i << " " << i+1 << " " << j << endl;
//                      return true;
//                 }

//                 // c,b,a
//                  if(check == 5){
//                     //   cout<<check<<endl;
//                     cout << j+1 << " " << n << " " << i+1 << " " << j << " " << 1 << " " << i << endl;
//                      return true;
//                 }

//                 // c,a,b
//                  if(check == 6){
//                     //   cout<<check<<endl;
//                     cout << i+1 << " " << j << " " << j+1 << " " << n << " " << 1 << " " << i << endl;
//                      return true;
//                 }



                
               
//             }
//         }
//     }
//     return false;
// }

// void solve()
// {
//     ll n;
//     cin >> n;
//     ll total = 0;
//     vl a(n + 1), b(n + 1), c(n + 1);
  
//     rep2(i, 1, n + 1) cin >> a[i];
//     rep2(i, 1, n + 1) cin >> b[i];
//     rep2(i, 1, n + 1)
//     {
//         cin >> c[i];
//         total += c[i];
//     }
//     ll atleast = (total + 2) / 3; // every onse hsould get aleast this much.

//     vl pa(n + 1), pb(n + 1), pc(n + 1);
//     for (ll i = 1; i <= n; ++i)
//         pa[i] = pa[i - 1] + a[i];
//     for (ll i = 1; i <= n; ++i)
//         pb[i] = pb[i - 1] + b[i];
//     for (ll i = 1; i <= n; ++i)
//         pc[i] = pc[i - 1] + c[i];

//     int i = 1;
//     if (partition(pa, pb, pc, n, atleast,1))
//         return;
//     if (partition(pa, pc, pb, n, atleast,2))
//         return;
//     if (partition(pb, pa, pc, n, atleast,3))
//         return;
//     if (partition(pb, pc, pa, n, atleast,4))
//         return;
//     if (partition(pc, pb, pa, n, atleast,5))
//         return;
//     if (partition(pc, pa, pb, n, atleast,6))
//         return;

//     cout << -1 << endl;
// }

// int main()
// {

// #ifndef ONLINE_JUDGE
//     freopen("Error.txt", "w", stderr);
// #endif

//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
// }
