#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    ll n, k;
    cin >> n >> k;
    vl a(10, 0);
    ll product = 1;
    int i = 0;
    
    // Extract digits into a[]
    while(n > 0) {
        a[i] = n % 10;
        n /= 10;
        i++;
    }
    
    // Sort only the digits extracted
    sort(a.begin(), a.begin() + i);
    
    while(k--) {
        if(a[0] == 9) {
            break;
        }
        a[0]++;          // increment smallest digit
        sort(a.begin(), a.begin() + i);
    }

    // Multiply only the digits extracted
    for(int j = 0; j < i; j++) {
        product *= a[j];
    }

    cout << product << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
