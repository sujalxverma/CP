#include <stdio.h>
#include <stdlib.h>
const int inf = 1e9;
int main(int argc, char *argv[]) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);

        int *dp = (int *)calloc(n + 5, sizeof(int));
        int *a = (int *)calloc(n + 5, sizeof(int));
        for (int i = 0; i < n + 5; i++) {
            dp[i] = inf;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            dp[a[i]] = 1;
        }

        for (int i = 1; i <= n; i++) {
            if (dp[i] == 1) {
                continue;
            }
            for (int j = 1; j * j <= i; j++) {
                if (i % j == 0) {
                    if (dp[i] < dp[i / j] + dp[j]) {
                        dp[i] = dp[i];
                    } else {
                        dp[i] = dp[i / j] + dp[j];
                    }
                    // dp[i] = min(dp[i], dp[i / j] + dp[j]);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (dp[i] == inf) {
                printf("-1 ");
            } else {
                printf("%d ", dp[i]);
            }
        }
        printf("\n");
    }
}