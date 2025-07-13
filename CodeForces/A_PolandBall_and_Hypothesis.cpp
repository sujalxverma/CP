#include "bits/stdc++.h"
using namespace std;
typedef vector<int> vi;
#define rep(i, a, b) for (int i = a; i < b; i++)
typedef unordered_map<int, int> umap;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
typedef long long ll;
#define even(a) (((a) % 2) == 0 ? 1 : 0)
#define rev(v) reverse(v.begin(), v.end())
#define prime(n) ([](int num) {if (num <= 1) return false;if (num == 2) return true;if (num % 2 == 0) return false;for (int i = 3; i <= std::sqrt(num); i += 2) {if (num % i == 0) return false;}return true; })(n)
#define gcd(a, b) ([](int x, int y) {while (y != 0) { int temp = y;y = x % y; x = temp;}return x; })(a, b)
#define lcm(a, b) (a * b / gcd(a, b))
#define sorted(v) sort(v.begin(), v.end())
#define line cout << endl



void solve() {
  int n;
  cin >> n;
if(n==1){
    cout<<3<<endl;
    return ;
}
  if((n&1) == 1){
    cout<<1<<endl;
  }else{
    cout<<2<<endl;
  }
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // int t;
  // cin >> t;
  // while (t--) {
  solve();
  // }
}