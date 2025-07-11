



/*
🧠 What This Code Teaches (Conceptually)

1. Two-pointers / Binary Search on Sorted Array:
   - The approach follows the "fix one, search the rest" pattern.
   - For each fixed element a[i], we use binary search to efficiently find
     how many a[j] (where j > i) satisfy a given condition.

2. Efficient Pair Counting:
   - A brute-force solution to count valid (i, j) pairs would take O(n^2) time.
   - By leveraging the sorted array and binary search (upper_bound),
     we reduce the inner loop to O(log n), resulting in an overall time
     complexity of O(n log n).

3. Use of upper_bound:
   - upper_bound returns an iterator to the first element greater than a given value.
   - This makes it perfect for range-based queries, especially when working
     with sorted arrays.

4. Index Math and Iterator Arithmetic:
   - Carefully converting iterators to indices and adjusting bounds is
     critical when using STL functions like upper_bound.
   - Getting these details right is an essential skill in C++ competitive programming.
*/


void solve()
{
    int n;
    n = 10;
    vector<int> a = {2, 4, 5, 6, 8, 9, 13, 19, 23, 24};
    // find number of pairs such that after removing a(i) and a(j) the sum > 10.
    int x = 21;
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int rem = x - a[i]; // upto this element i can consider.
        if (rem <= 0)
        {
            continue;
        }
        auto it = upper_bound(a.begin() + 1 + i, a.end(), rem);
        int idx;
        if (it == a.end())
        {
            idx = n - 1;
        }
        else
        {
            idx = it - a.begin() - 1;
        }
        int pairs = idx - i;

        count+=pairs;
        cout << i << "  :  " << a[i] << "  :  " << pairs << endl;
    }
    cout << endl;
    cout << count << endl;
}