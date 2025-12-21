#include "bits/stdc++.h"
using namespace std;
using ll = long long;

/*
N.
    Approach (Reverse Construction, No Bitmasks):

    Instead of constructing the array from zeroes, we reverse the process.
    We are given an array a[], initially built by repeatedly adding k^i
    to exactly one position at step i (or skipping the step).

    Key Observations:
    1) Each power k^i can be used at most once (one position per step).
    2) Since k^i > sum of all smaller powers (k^0 + k^1 + ... + k^(i-1)),
       at any stage there can be at most ONE element in the array
       that is >= k^i.
    3) If two or more elements are >= k^i, it would mean k^i was added
       multiple times in the same step — which is impossible.

    Algorithm:
    - Find the maximum power 's' such that k^s <= 1e16 (max possible a[i]).
    - Process powers from largest to smallest (s down to 0).
    - For each power k^i:
        * Find at most one index j such that a[j] >= k^i.
        * Subtract k^i from that element.
        * If more than one element needs k^i, construction is impossible.
    - After processing all powers, check whether all elements become 0.

    Correctness:
    - This simulates undoing each operation in reverse order.
    - The uniqueness condition ensures each power is assigned to
      at most one position, matching the problem constraints.

    Complexity:
    - At most ~60 powers (since k^i <= 1e16)
    - n <= 30
    - Time complexity: O(n * log_k(1e16)), easily fast enough.

    If all elements reduce to zero → YES
    Otherwise → NO
*/


long long power(long long k, long long i) {
    long long result = 1;
    while (i > 0) {
        if (i & 1) result *= k;
        k *= k;
        i >>= 1;
    }
    return result;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll maxPower = 0;
        int i = 0;
        ll nums = 1;
        while (nums < 1e16)
        {
            nums *= k;
            i++;
        }
        maxPower = i;

       
        for (int i = maxPower; i >= 0; i--)
        {
           
            ll value = power(k,i);
            for(int i = 0; i < n ; i++){
                if(a[i] >= value){
                    a[i] -= value;
                    break;
                }
            }

        }
        bool f = true;
        for(int i = 0; i < n ; i++){
            if(a[i] != 0){
                f = false;
                cout<<"NO\n";
                break;
            }
        }
        if(f){
            cout<<"YES\n";
        }
    }
    return 0;
}