// Lower and Upper Bound in C++ STL

/*
  1. lower_bound:
     - Returns iterator to the first element >= x.
  
  2. upper_bound:
     - Returns iterator to the first element > x.
  
  3. a.begin() points to index 0.
  
  4. a.end() points to one past the last index (i.e., index a.size()), which is outside the vector range.
  
  5. a.end() is exclusive; the upper limit in STL ranges is always exclusive.
*/


vector<int> a = {3, 4, 8, 10, 13, 21, 34, 39, 40, 40, 40, 57, 59, 60};

// 1. Return iterator (not index)
auto it = lower_bound(a.begin() + 8, a.end(), 40);

// 2. Convert iterator to index
int index = it - a.begin();

// 3. Start searching from kth index (inclusive)
int k = 9;
lower_bound(a.begin() + k, a.end(), 40);

// 4. Position where x could be inserted if not present (even in empty range)
lower_bound(a.begin(), a.begin(), 100);  // always returns a.begin()

// 5. Search in specific subrange [i, j)
int i = 5;
int j = 10;
lower_bound(a.begin() + i, a.begin() + j, 100);

// 6. Find frequency of an element x
int x = 40;
int freq = upper_bound(a.begin(), a.end(), x) - lower_bound(a.begin(), a.end(), x);

// 7. Binary search using lower_bound
auto it2 = lower_bound(a.begin(), a.end(), x);
if (it2 != a.end() && *it2 == x)
    cout << "Found at index " << it2 - a.begin() << endl;
else
    cout << "Not found" << endl;

// 8. Insert x while keeping the vector sorted
auto pos = lower_bound(a.begin(), a.end(), x);
a.insert(pos, x);


