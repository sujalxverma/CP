// VERMA
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

//------------------------------------------------------------------------------------------------------------//
//                                          Here you go

bool f(ll &val, ll &idx, ll &x, ll &m) { // This is the predicate function
    // Checks if the cost to buy (idx+1) items on the m-th day is within budget x
    if (val + 1LL * (idx + 1) * (m - 1) <= x) {  // m-1 ? b/c at least 1 time i can select that number.
        return true;
    }
    return false;
}

ll bs(ll &val, ll &idx, ll &x) {
    ll s = 1;
    ll e = 1e9 + 5;
    ll ans = 0;
    while (s <= e) {
        ll m = s + (e - s) / 2;
        if (f(val, idx, x, m)) {
            ans = m;
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    return ans;
}

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> cost(n);
    for (ll i = 0; i < n; i++) {
        cin >> cost[i];
    }
    sort(cost.begin(), cost.end());

    vector<ll> prefix(n);
    prefix[0] = cost[0];
    for (ll i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + cost[i];
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += bs(prefix[i], i, x);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}
