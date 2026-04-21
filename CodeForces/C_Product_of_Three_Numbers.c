#include <stdio.h>

void solve() {
    int n;
    scanf("%d", &n);
    int capacity = 1e6;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int value = i;
            int num = n / value;

            for (int j = 2; j * j <= num; j++) {
                if (num % j == 0 && value != j && value != (num / j) && (j != (num / j))) {
                    printf("YES\n");
                    printf("%d %d %d\n", value, j, num / j);
                    return;
                }
            }
        }
    }
    printf("NO\n");

    return;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}