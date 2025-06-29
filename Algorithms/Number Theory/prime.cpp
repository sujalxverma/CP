

// check if a number if prime or not.
bool prime(long long n){
    if(n<2){
        return false;
    }
    for(long long i = 2 ; i <= sqrt(n) ; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

// all factors of n including 1.
vector<ll> factors(ll n) {
    vector<ll> ans;
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i != n / i) {  // avoid duplicates
                ans.push_back(n / i);
            }
        }
    }
    if(n>1){
        ans.push_back(1);
        ans.push_back(n);
    }
    return ans;
}


// prime factors of n.
vector<long long > primeFactors(long long n)
{
    vector<long long> f;
    for (int x = 2; x * x <= n; x++)
    {
        while (n % x == 0)
        {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1)
        f.push_back(n);
    return f;
}


// all primes b/w 2 and n.
// O(nlogn)
vector<ll> sieveOfEratosthenes(ll n) {
    vector<ll> numbers(n + 1, 0);  // 0 = prime, 1 = not prime

    for (ll i = 2; i * i <= n; i++) {
        if (numbers[i]) continue;

        for (ll j = i * i; j <= n; j += i) {
            numbers[j] = 1;  // mark as not prime
        }
    }

    vector<ll> primeFactors;
    for (ll i = 2; i <= n; i++) {
        if (!numbers[i]) {
            primeFactors.push_back(i);
        }
    }

    return primeFactors;
}



// bitsetSeive
const int N = 1e8 + 1;
bitset<N> is_prime;

void bitsetSieve(int n) {
    is_prime.set(); // set all bits to 1 (i.e., mark all as prime)
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; 1LL * i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = 0;
        }
    }
}


// Segmented Seive
// Simple sieve up to sqrt(high)
vector<ll> simpleSieve(ll limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= limit; j += i)
                is_prime[j] = false;
        }
    }

    vector<ll> primes;
    for (ll i = 2; i <= limit; ++i)
        if (is_prime[i])
            primes.push_back(i);

    return primes;
}

void segmentedSieve(ll low, ll high) {
    ll limit = sqrt(high) + 1;
    vector<ll> primes = simpleSieve(limit);

    vector<bool> is_prime(high - low + 1, true);

    for (ll p : primes) {
        ll start = max(p * p, (low + p - 1) / p * p);
        for (ll j = start; j <= high; j += p)
            is_prime[j - low] = false;
    }

    if (low == 1) is_prime[0] = false;

    for (ll i = low; i <= high; ++i) {
        if (is_prime[i - low])
            cout << i << " ";
    }
    cout << "\n";
}

// Modular Exponention
ll mod_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}