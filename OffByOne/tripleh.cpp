
/*
    This function counts the number of pairs (i, j) in a sorted array `a` such that:
        x <= a[i] + a[j] <= y
    where i < j.

    Key Concepts Demonstrated:
    1. Binary Search (upper_bound):
       - For each fixed element a[i], we use upper_bound to quickly find the range of valid a[j]
         that satisfy the sum condition.
       - upper_bound returns the first element greater than a given value, allowing us to find
         boundaries efficiently.

    2. Efficient Pair Counting:
       - Instead of checking all pairs (O(n^2)), this approach reduces complexity to O(n log n),
         performing two binary searches per element.

    3. Iterator and Index Arithmetic:
       - Converting iterators returned by upper_bound into array indices to calculate counts correctly.
       - Careful handling of the upper_bound results and adjusting indices (e.g., subtracting 1).

    4. Handling Boundary Cases:
       - Ensuring the loop runs only till n-1 since pairs require j > i.
       - Validating that the calculated pair count is positive before adding.

    5. Sorted Array Assumption:
       - The array must be sorted for upper_bound to work correctly and for the logic to hold.

    This technique is widely used in problems involving pair sums within ranges and illustrates
    an important optimization pattern in competitive programming.
*/

/*
    For each fixed element a[i], we want to find all a[j] such that:
        x <= a[i] + a[j] <= y

    Rearranging for a[j]:
        x - a[i] <= a[j] <= y - a[i]

    To use upper_bound (which finds the first element greater than a value),
    we adjust the bounds as follows:

    - xlimit = x - 1 - a[i];
      We want the first a[j] that is **greater than x - 1 - a[i]**,
      which is equivalent to a[j] >= x - a[i].
      Since upper_bound finds first element > xlimit,
      setting xlimit = x - 1 - a[i] ensures we get the first a[j] satisfying
      the lower bound (a[j] >= x - a[i]).

    - ylimit = y - a[i];
      We want all a[j] <= y - a[i].
      upper_bound finds the first element > ylimit,
      so all elements before that iterator satisfy the upper bound condition.
*/


void solve()
{
    int n = 10;
    vi a = {2, 4, 5, 6, 8, 9, 13, 19, 23, 24};
    int x = 13;
    int y = 23;

    ll count = 0;
    for (int i = 0; i <= n - 1; i++)  // note: n-1 because we need j > i
    {
        int xlimit = x - 1 - a[i];   // for lower bound
        int ylimit = y - a[i];       // for upper bound

        auto it1 = upper_bound(a.begin() + i + 1, a.end(), xlimit);
        auto it2 = upper_bound(a.begin() + i + 1, a.end(), ylimit);

        int idx1 = it1 - a.begin();  // absolute index of first element > xlimit
        int idx2 = (it2 - a.begin()) - 1; // last element <= ylimit

        int pairs = idx2 - idx1 + 1;
        if (pairs > 0) count += pairs;

        cout << i << "  :  " << a[i] << "  :  " << max(0, pairs) << endl;
    }
    cout << endl;
    cout << count << endl;
}

