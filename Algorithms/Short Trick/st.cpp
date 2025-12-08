
/*
1. Having an array A, with duplicates present, want to only keep single
   occurence of each element.
*/
sort(a.begin(),a.end());
a.erase(unique(a.begin(),a.end()),a.end());

/*
2. Convert ll to string.
   Convert string to ll.
*/
ll x = 232323;
string s = to_string(x);

string s = "987654321";
long long x = stoll(s);


