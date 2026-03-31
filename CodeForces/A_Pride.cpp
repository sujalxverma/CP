#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
vector<int> a;
/*
- IF GCD OF WHOLE ARRAY IS NOT 1, THEN ANSWER IS -1.
- IF NUMBER OF 1 IS CNT1 > 0, THEN I CAN TAKE THOSE AS MY BASE, AND SORT OF RUN BFS LOGIC, THEN IT TAKES (N - CNT1) STEPS,
  WHICH ARE MINIUM BY THE WAY.
- OTHERWISE WE HAVE TO FIND MINIUM LENGTH OF THE SEGMENT WHOSE GCD IS 1, SAY LENGTH IS L, THEN IT TAKES
  (N - 2 + L) STEPS.
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    a.resize(n);
    int g = 0;
    int cnt1 = 0; // count number of 1.
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g = gcd(g, a[i]);
        if (a[i] == 1)
            cnt1++;
    }
    if (g != 1) {
        cout << "-1\n";
        return 0;
    }
    if (cnt1 > 0) {
        cout << n - cnt1 << "\n";
        return 0;
    }
    /*
        // check for any adjacent pair for which gcd is 1.
        int idx = -1;
        for (int i = 0; i < n - 1; i++) {
            if (gcd(a[i], a[i + 1]) == 1) {
                idx = i;
                break;
            }
        }
        if (idx != -1) {
            // we found an adjacent pair.
            cout << n << "\n";
            return 0;
        }
        // cout << n + 1 << "\n";  not accurate, leads to wrong answer on TC 4.
    */
    int l = -1;
    int r = -1;
    int minLength = 1e9;
    for (int i = 0; i < n; i++) {
        int g = 0;
        for (int j = i; j < n; j++) {
            g = gcd(g, a[j]);
            if (g == 1 && (j - i + 1) < minLength) {
                minLength = (j - i + 1);
                l = i;
                r = j;
            }
        }
    }
    // cout << minLength << "\n";
    cout << minLength + n - 2 << "\n";
}
