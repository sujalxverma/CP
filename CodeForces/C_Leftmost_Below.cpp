#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rep2(i, a, b) for (long long i = a; i < b; i++)

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

bool checkIncrease(vl &a){
    for(ll i = 1 ; i < a.size() ; i++){
        if(a[i]<= a[i-1]){
            return false;
        }
    }
    return true;
}

bool checkDecrease(vl &a){
    for(ll i = 1 ; i < a.size() ; i++){
        if(a[i]>= a[i-1]){
            return false;
        }
    }
    return true;
}

// Checks if array first strictly decreases, then strictly increases ("valley" shape)
bool DecToInc(const vl &a) {
    ll n = a.size();
    if(n < 3) return false;
    int i = 1;
    // strictly decreasing prefix
    while(i<n && a[i] < a[i-1]) i++;
    if(i == 1 || i == n) return false; // must be at least one decrease, then at least one increase
    // strictly increasing suffix
    while(i < n && a[i] > a[i-1]) i++;
    return (i == n);
}

void solve(){
    ll n;
    cin >> n;
    vl a(n);
    rep2(i,0,n) cin >> a[i];

    if(checkIncrease(a)) {
        cout << "NO" << endl;
    } else if(checkDecrease(a)) {
        cout << "YES" << endl;
    } else if(DecToInc(a)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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
    return 0;
}
