

// check if a number if prime or not.
bool prime(long long n)
{
    if (n < 2)
    {
        return false;
    }
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// all factors of 'n' including 1.
vector<ll> factors(ll n)
{
    vector<ll> ans;
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if (i != n / i)
            { // avoid duplicates
                ans.push_back(n / i);
            }
        }
    }
    if (n > 1)
    {
        ans.push_back(1);
        ans.push_back(n);
    }
    return ans;
}

// prime factors of n.
vector<long long> primeFactors(long long n)
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
// O(nloglogn)

vector<ll> sieveOfEratosthenes(ll n)
{
    vector<ll> numbers(n + 1, 0); // 0 = prime, 1 = not prime

    for (ll i = 2; i * i <= n; i++)
    {
        if (numbers[i])
            continue;

        for (ll j = i * i; j <= n; j += i)
        {
            numbers[j] = 1; // mark as not prime
        }
    }

    vector<ll> primeFactors;
    for (ll i = 2; i <= n; i++)
    {
        if (!numbers[i])
        {
            primeFactors.push_back(i);
        }
    }

    return primeFactors;
}

// bitsetSeive
const int N = 1e8 + 1;
bitset<N> is_prime;

void bitsetSieve(int n)
{
    is_prime.set(); // set all bits to 1 (i.e., mark all as prime)
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; 1LL * i * i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = 0;
        }
    }
}

// Segmented Seive
// Simple sieve up to sqrt(high)
vector<ll> simpleSieve(ll limit)
{
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= limit; ++i)
    {
        if (is_prime[i])
        {
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

void segmentedSieve(ll low, ll high)
{
    ll limit = sqrt(high) + 1;
    vector<ll> primes = simpleSieve(limit);

    vector<bool> is_prime(high - low + 1, true);

    for (ll p : primes)
    {
        ll start = max(p * p, (low + p - 1) / p * p);
        for (ll j = start; j <= high; j += p)
            is_prime[j - low] = false;
    }

    if (low == 1)
        is_prime[0] = false;

    for (ll i = low; i <= high; ++i)
    {
        if (is_prime[i - low])
            cout << i << " ";
    }
    cout << "\n";
}

// Modular Exponention
ll mod_pow(ll base, ll exp, ll mod)
{
    ll res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

// finds all the subsequence of a string.
vector<string> generateSubsequences(const string &str)
{
    int n = str.size();
    vector<string> subsequences;

    // There are 2^n possible subsequences
    int total = 1 << n; // same as pow(2, n)

    for (int mask = 1; mask < total; ++mask)
    { // start from 1 to skip empty subsequence if needed
        string subseq = "";
        for (int i = 0; i < n; ++i)
        {
            // Check if i-th bit is set in mask
            if (mask & (1 << i))
            {
                subseq += str[i];
            }
        }
        subsequences.push_back(subseq);
    }

    return subsequences;
}

// computes factorials upto N, and stores in vector
std::vector<long long> compute_factorials(int n)
{
    std::vector<long long> factorials(n + 1);
    factorials[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        factorials[i] = (factorials[i - 1] * i) % MOD;
    }
    return factorials;
}

// Computes inverse factorials up to n using precomputed factorials
std::vector<long long> compute_inv_factorials(int n, const std::vector<long long> &fact)
{
    std::vector<long long> inv_fact(n + 1);
    inv_fact[n] = mod_pow(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; --i)
    {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
    return inv_fact;
}

// computes inverse from 1 to N.
std::vector<int> compute_inverses(int n)
{
    std::vector<int> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        inv[i] = MOD - (int)((1LL * (MOD / i) * inv[MOD % i]) % MOD);
    }
    return inv;
}

// Custom bit_ceil for unsigned long long
unsigned long long bit_ceil(unsigned long long x)
{
    if (x <= 1)
        return 1;
    x--;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    return x + 1;
}

// Fast multiplication mod m (avoid overflow)
ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
        {
            res = (res + a) % mod;
        }
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

// Miller-Rabin primality test (deterministic for 64-bit)
bool miller_rabin(ll n)
{
    if (n < 2)
        return false;
    ll r = 0;
    ll d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        r++;
    }
    // Test bases for 64-bit integers (deterministic set)
    vector<ll> testBases = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    for (ll a : testBases)
    {
        if (a >= n)
            break;
        ll x = modpow(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool composite = true;
        for (ll i = 0; i < r - 1; i++)
        {
            x = mulmod(x, x, n);
            if (x == n - 1)
            {
                composite = false;
                break;
            }
        }
        if (composite)
            return false;
    }
    return true;
}

// Find a non-trivial factor of n quickly.
ll pollard_rho(ll n)
{
    if (n % 2 == 0)
        return 2;
    ll x = rand() % (n - 2) + 2;
    ll y = x;
    ll c = rand() % (n - 1) + 1;
    ll d = 1;
    while (d == 1)
    {
        x = (mulmod(x, x, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        d = __gcd(abs(x - y), n);
        if (d == n)
            return pollard_rho(n);
    }
    return d;
}

// Recursively factorize n into prime factors and store them in factors.

void primeFactors(ll n, vector<ll> &factors)
{
    if (n == 1)
        return;
    if (miller_rabin(n))
    {
        factors.push_back(n);
        return;
    }
    ll divisor = pollard_rho(n);
    factor(divisor, factors);
    factor(n / divisor, factors);
}

// as i iterates over the array, it calculates the MEX of that segment.
unordered_map<int, int> freq;
int current_mex = 0;

for (int i = 1; i <= n; ++i)
{
    freq[a[i - 1]]++;

    // Update current_mex
    while (freq.count(current_mex))
    {
        current_mex++;
    }

    cout << "MEX of a[1.." << i << "] is: " << current_mex << '\n';
}
/*
 * The while loop starts from the current MEX guess (current_mex). If you replace while with if, it will give wrong answer.
 * While the number current_mex is present in the frequency map
 * (meaning we've seen it in the prefix),
 * it increases current_mex by 1, moving on to check the next integer.
 */

// Binary Exponention
ll expo(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = a * ans;
        }
        a = a * a;
        b = b >> 1;
    }
    return ans;
}

// optimised segmented sieve

vector<int> simple_sieve(int limit)
{
    int sqrt_limit = sqrt(limit);
    vector<bool> is_prime(sqrt_limit + 1, true);
    vector<int> primes;

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= sqrt_limit; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = i * 2; j <= sqrt_limit; j += i)
                is_prime[j] = false;
        }
    }
    return primes;
}

void segmented_sieve(int n)
{
    int sqrt_n = sqrt(n);
    vector<int> primes = simple_sieve(n);

    vector<bool> is_prime(segment_size);
    ll count = (n >= 2 ? 1 : 0); // Count 2 as prime

    // Process odd segments starting from 3
    for (ll low = 2; low <= n; low += segment_size)
    {
        ll high = min(low + segment_size - 1, (ll)n);
        fill(is_prime.begin(), is_prime.end(), true);

        for (int p : primes)
        {
            ll start = max(p * p, ((low + p - 1) / p) * p);
            for (ll j = start; j <= high; j += p)
                is_prime[j - low] = false;
        }

        for (ll i = low; i <= high; ++i)
        {
            if (is_prime[i - low])
            {
                if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0)
                    continue;
                // Uncomment below to print each prime
                // cout << i << '\n';
                ++count;
            }
        }
    }

  
}


// nCr
vector<ll> fact(MAXN + 1), invfact(MAXN + 1);

// Fast modular exponentiation
ll mod_pow(ll base, ll exp) {
    ll result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

// Precompute factorials and inverse factorials
void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
        fact[i] = (fact[i - 1] * i) % MOD;
    invfact[MAXN] = mod_pow(fact[MAXN], MOD - 2);
    for (int i = MAXN - 1; i >= 0; --i)
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
}

// nCr modulo MOD
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invfact[r]) % MOD) * invfact[n - r]) % MOD;
}

// Calculate MEX for a range in a vector.
int calculateMex(const std::vector<int>& vec, int start, int end) {
    std::unordered_set<int> seen;
    // Insert elements from the subrange into the set
    for (int i = start; i <= end && i < (int)vec.size(); ++i) {
        if (vec[i] >= 0) {
            seen.insert(vec[i]);
        }
    }
    // Find the smallest non-negative integer not in the set
    int mex = 0;
    while (seen.count(mex)) {
        ++mex;
    }
    return mex;
}