#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

/*
n = x+y
if n is odd, then we can make n odd subtrees, else n-1 subtrees.

*/

int main(int argc, char *args[]) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int n = x + y;
        int d = y - x;
        if (n % 2 == 0 && x == 0) {
            printf("NO\n");
            continue;
        }
        if (n % 2 == 1 && y == 0) {
            printf("NO\n");
            continue;
        }
        if (x > y) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        int mn = 2 * x + (d % 2);
        for (int i = 2; i <= mn; i++) {
            printf("%d %d\n", i - 1, i);
        }
        for (int i = mn + 1; i <= n; i++) {
            printf("%d %d\n", mn, i);
        }
    }
}