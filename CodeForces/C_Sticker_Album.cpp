#include "bits/stdc++.h"
using namespace std;

#define int ll
#define endl '\n'
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define re resize
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin()+1, (x).end()
#define loop(i, n) for(int i = 0; i < n; ++i)
#define loop1(i, n) for(int i = 1; i <= n; ++i)
#define print(x) cout << #x << ": " << x << endl << flush
typedef long long ll;
typedef vector<int> vi;
typedef array<int, 2> ii;
typedef array<int, 3> ti;
typedef vector<ii> vii;
typedef vector<ti> vti;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef priority_queue<int> pq;

template<class T>
bool ckmin(T &a, T b) { bool B = a > b; a = min(a, b); return B; }

template<class T>
bool ckmax(T &a, T b) { bool B = a < b; a = max(a, b); return B; }

const int inf = 1e17;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    vd dp(n+1), p(n+1);

    if(a) {
        for(int i = 1; i <= min(a, n); i++) {
            dp[i] = 1;
            p[i] = p[i-1] + dp[i];
        }
        for(int i = min(a, n) + 1; i <= n; i++) {
            int l = i - a;
            int r = max(i - b, 1ll);
            dp[i] = 1 + (p[l] - p[r-1]) / (b - a + 1);
            p[i] = dp[i] + p[i-1];
        }
    } else {
        for(int i = 1; i <= n; i++) {
            int l = i - 1;
            int r = max(i - b, 1ll);
            dp[i] = ((b + 1) + (p[l] - p[r-1])) / b;
            p[i] = dp[i] + p[i-1];
        }
    }

    cout << dp[n] << endl;
}

signed main() {
    fast_io;
    cout << setprecision(10);
    int t = 1;
    while(t--)
        solve();
    return 0;
}
