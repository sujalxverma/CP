
/*
1. Having an array A, with duplicates present, want to only keep single
   occurence of each element.
*/
sort(a.begin(), a.end());
a.erase(unique(a.begin(), a.end()), a.end());

/*
2. Convert ll to string.
   Convert string to ll.
*/
ll x = 232323;
string s = to_string(x);

string s = "987654321";
long long x = stoll(s);

/*
3. print decimal numbers with last 10 digits after decimal.
*/
double x = 3.141592653589793;
cout << fixed << setprecision(10) << x << "\n";
