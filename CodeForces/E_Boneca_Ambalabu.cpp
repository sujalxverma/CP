#include "bits/stdc++.h"
using namespace std;
/*
--------------------------------------------------------------
🔍 Problem Statement:
Given an array of integers, for each element a_k in the array,
compute the sum:
    (a_k ^ a_1) + (a_k ^ a_2) + ... + (a_k ^ a_n)
Your goal is to find the maximum such sum across all k.

--------------------------------------------------------------
🧠 Strategy:

1. Observation:
   - XOR is both associative and commutative, so we can consider
     each bit position independently.
   - XOR flips a bit if two bits differ, and leaves it as 0 if they are the same.

2. Preprocessing:
   - For each bit position (0 to 29), count how many numbers in the array
     have that bit set. Store this in an array `cnt[30]`.

3. For each element a_k in the array:
   - For each bit position j:
     - If a_k has bit j **set**:
         Then, it will XOR to 1 with every number that has bit j **unset**.
         So add: (n - cnt[j]) * (1 << j) to the sum.
     - If a_k has bit j **unset**:
         Then, it will XOR to 1 with every number that has bit j **set**.
         So add: cnt[j] * (1 << j) to the sum.
   - This gives total XOR sum for a_k in O(30) time.

4. Finally, return the maximum such XOR sum across all elements.

--------------------------------------------------------------
🕒 Time Complexity:
- Preprocessing: O(n * 30)
- Per element: O(30)
- Total: O(n * 30) = Efficient for n ≤ 1e5

--------------------------------------------------------------
*/

void solve() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    vector<long long> cnt(30, 0);

    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        for (long long j = 0; j < 30; j++) {
            cnt[j] += ((arr[i] >> j) & 1);
        }
    }

    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        long long tot = 0;
        for (long long j = 0; j < 30; j++) {
            bool bit_set = ((arr[i] >> j) & 1);
            if (bit_set)
                tot += (1LL << j) * (n - cnt[j]);  // it means , cnt[j] have bitset , so its xor will be zero, so we only count (n -cnt[j])
            else
                tot += (1LL << j) * cnt[j];
        }
        ans = max(ans, tot);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
