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

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    if (x != 1) {
        cout << "YES\n";
        cout << n << "\n";
        for (int i = 0; i < n; i++) cout << "1 ";
        cout << "\n";
    } else if (k == 1 || (k == 2 && n % 2 == 1)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << n / 2 << "\n";
        if (n % 2 == 1) {
            cout << "3 ";
            for (int i = 1; i < n / 2; i++) cout << "2 ";
        } else {
            for (int i = 0; i < n / 2; i++) cout << "2 ";
        }
        cout << "\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}