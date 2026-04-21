#include <math.h>
#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[3200];

        int idx = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int ans = -1e9;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = (ans > (arr[i] ^ arr[j])) ? ans : (arr[i] ^ arr[j]);
            }
        }
        printf("%d\n", ans);
    }
}