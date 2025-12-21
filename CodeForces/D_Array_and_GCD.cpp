#include "bits/stdc++.h"
using namespace std;
using ll = long long;

vector<ll> get_first_n_primes(int need) {
    int LIMIT = 6000000; // enough for first 4e5 primes
    vector<bool> is_prime(LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; 1LL * i * i <= LIMIT; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= LIMIT; j += i)
                is_prime[j] = false;
        }
    }

    vector<ll> primes;
    primes.reserve(need);
    for (int i = 2; i <= LIMIT && (int)primes.size() < need; i++) {
        if (is_prime[i])
            primes.push_back(i);
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    const int MAXN = 400000;
    vector<ll> primes = get_first_n_primes(MAXN);

    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (ll &x : a) cin >> x;

        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }

        sort(a.begin(), a.end(), greater<ll>());

        ll sumA = 0, sumP = 0;
        int best = 0;

        for (int i = 0; i < n; i++) {
            sumA += a[i];
            sumP += primes[i];
            if (sumA >= sumP)
                best = i + 1;
            else
                break;
        }

        cout << n - best << "\n";
    }

    return 0;
}
