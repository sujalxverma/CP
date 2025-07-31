#include "bits/stdc++.h"

using namespace std;
int main() {
    int t;
    if (scanf("%d", &t)!=1) return 0;
    while (t--) {
        int n;
        scanf("%d", &n);
        long long sum = 0;
        int cnt0 = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            sum += x;
            if (x == 0) cnt0++;
        }
       
        printf("%lld\n", sum + cnt0);
    }
    return 0;
}