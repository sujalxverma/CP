
/*
Think of a sliding window as:
 "A flexible rope between two poles (i and j) — expand and shrink the rope while keeping total weight (sum, count, etc.)
  within a limit."

Use sliding window when you’re "scanning forward" through a list,
and can add/remove elements efficiently from the window while maintaining some property (like sum or count).
*/

// sliding window over an array, a/c to condition of sum <= k.
// 0 based indexing.

int left = 0;
long long sum = 0;
int maxLen = 0;
for (int right = 0; right < n; ++right)
{
    sum += a[right];

    while (sum > k)
    {
        sum -= a[left];
        left++;
    }

    // update result
    maxLen = max(maxLen, right - left + 1);
}
