//  Lower and Upper bound

/*

 1. lower_bound : return iterator(pointer) for that element(not index) which is either greater or equal to x.
 2. upper_bound : return iterator(pointer) for that element(not index) which is either greater to x.
 3. a.begin() points to index 0.
 4. a.end() points to end of vector, i.e nth index, which is beyond vector range.
 5. a.end() is exlucive, generally the upper limit is exclusive.

*/



// 1. return iterator.
 auto it = lower_bound(a.begin()+8,a.end(),40);

// 2. returns index to that element.
 int index = it - a.begin();

// 3. returns index starting searching from kth index, i.e starting from 9th index (this index is inclusive).
 int k = 9;
 lower_bound(a.begin()+k,a.end(),40);

 // 4. returns at which position x could be inserted if its not present.
 //   its full range, limiting the range will give index accordingly.
 //   lower_bound(a.begin(),a.begin(),100);

// 5. to check specific range.
 int i = 5;
 int j = 10;
 lower_bound(a.begin() + i, a.begin() + j,100);

 // 6. find frequency of an element.
 int x = 40;
 int freq = upper_bound(a.begin(), a.end(), x) - lower_bound(a.begin(), a.end(), x);

// 7. Binary Search.
 auto it = lower_bound(a.begin(), a.end(), x);
 if (it != a.end() && *it == x)
   cout << "Found at index " << it - a.begin() << endl;
 else
   cout << "Not found" << endl;

// 8. insert x while keeping vector sorted.
 auto pos = lower_bound(a.begin(), a.end(), x);
 a.insert(pos, x);



