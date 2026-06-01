#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll neginf = -1e18;
long long maxSubarraySum(const std::vector<ll> &a) {
    long long best = LLONG_MIN;
    long long cur = 0;

    for (ll x : a) {
        cur = std::max(1LL * x, cur + x);
        best = std::max(best, cur);
    }

    return best;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll k;
        cin >> k;
        string s;
        cin >> s; // 0->lost , 1->know
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll cnt = 0;
        for (ll i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt++;
            }
        }
        if (cnt == 0) {
            ll sum = maxSubarraySum(a);
            if (sum == k) {
                cout << "YES\n";
                for (auto &x : a) {
                    cout << x << " ";
                }
                cout << "\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }
        if (cnt == n) {
            cout << "YES\n";
            cout << k << " ";
            for (ll i = 1; i <= n; i++) {
                cout << neginf << " ";
            }
            cout << "\n";
            continue;
        }
        /*
        We want to make max subarray sum to be k.  abs(a[i]) <= 1e18
        if any segment with sum > k ,then No
        */

        vector<ll> p(n, 0), sf(n, 0);
        ll start = 0;
        ll end = n - 1;
        for (ll i = 0; i < n; i++) {
            if (s[i] != '0') {
                start = i;
                break;
            }
        }
        for (ll i = n - 1; i >= 0; i--) {
            if (s[i] != '0') {
                end = i;
                break;
            }
        }
        ll maxSum = 0;
        for (ll i = start; i <= end; i++) {
            if (s[i] == '1') {
                p[i] = a[i] + (i - 1 >= 0 ? p[i - 1] : 0);
                maxSum = max(maxSum, p[i]);
            } else {
                // continue;
            }
        }
        for (ll i = end; i >= start; i--) {
            if (s[i] == '1') {
                sf[i] = a[i] + (i + 1 < n ? p[i + 1] : 0);
                maxSum = max(maxSum, sf[i]);
            }
        }

        if (maxSum > k) {
            cout << "NO\n";
            continue;
        }
        if (maxSum == k) {
            cout << "YES\n";
            for (ll i = 0; i < n; i++) {
                if (s[i] == '0') {
                    cout << neginf << " ";
                }
                cout << a[i] << " ";
            }
            cout << "\n";
            continue;
        }
        cout << "YES\n";
        for (ll i = 0; i < n; i++) {
            if (s[i] == '0') {
                a[i] = neginf;
            }
        }
        for (ll i = 0; i < n; i++) {
            if (s[i] == '0') {
                ll v = k - (i + 1 < n ? s[i + 1] : 0) - (i - 1 >= 0 ? p[i - 1] : 0);
                a[i] = v;
                break;
            }
        }
        for (auto &x : a) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}