#include "bits/stdc++.h"
using namespace std;
#define int long long
vector<int> f;

vector<int> linearSieve(int n) {
    vector<int> primes;
    vector<int> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i])
            primes.push_back(i);
        for (int j = 0; j < (int)primes.size() && i * primes[j] <= n; j++) {
            isPrime[i * primes[j]] = 0;
            if (i % primes[j] == 0)
                break;
        }
    }
    return isPrime;
}

void solve(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> mp;
    vector<int> k(2e5 + 10); // existence array
    for (auto &x : a) {
        cin >> x;
        k[x] = 1;
        mp[x]++;
    }
    vector<int> isprime(n, 0);
    unordered_map<int, int> primefreq;
    vector<int> s; // stores prime
    for (int i = 0; i < n; i++) {
        if (f[a[i]] == 1) {
            // it is prime.
            isprime[i] = 1;
            s.push_back(a[i]);
            primefreq[a[i]]++;
        }
    }
    sort(begin(s), end(s));
    int ans = 0; // initital ans.
    for (int i = 0; i < (int)s.size() - 1; i++) {
        if (s[i] != s[i + 1]) {
            ans += primefreq[s[i]] * ((int)s.size() - i - 1);
        }
    }
    // cout << ans << "\n";
    // return;
    set<int> store;
    for (int i = 0; i < n; i++) {
        if (isprime[i] == 1 || a[i] == 1) {
            continue;
        }
        for (int j = 2; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                if (f[j] == 1 && f[a[i] / j] == 1) {
                    // if both are prime, then this number is semi prime.
                    ans++;
                    ans += primefreq[j];
                    if (j != a[i] / j) {
                        ans += primefreq[a[i] / j];
                    }
                    if (k[1] > 0) {
                        ans += k[1];
                    }
                    if (mp[a[i]] > 1) {
                        store.insert(a[i]);
                    }
                    break;
                }
            }
        }
    }
    for (auto &x : store) {
        // cout << x << " " << mp[x] << "\n";
        ans += (mp[x] * (mp[x] - 1)) / 2;
    }
    cout << ans << "\n";
}
// 4 17 12 18 13 2 18 8 17 21 15 19 14 5 6 21 8 6 22 4 17 22 17

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    f = linearSieve(2e5 + 100);
    while (t--) {
        solve();
    }
    return 0;
}