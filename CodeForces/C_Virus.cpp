#include "bits/stdc++.h"
#include <cstdio>
using namespace std;
const int N = 500005, inf = 2147483647, M = 1004535809;
int n, m, a[N], T, k;
struct str {
	int x, y;
}t[N];

// I really don't understand the solution.

int main() {
	scanf("%d", &T);
	while (T--) {
		k = 0;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; ++i)
			scanf("%d", &a[i]);
		sort(a + 1, a + 1 + m);
		for (int i = 2; i <= m; ++i)
			t[++k] = { a[i] - a[i - 1] - 1,2 };
		int num_tmp = a[1] + n - a[m] - 1;
		if (num_tmp > 0) {
			t[++k] = { num_tmp, 2 };
		}
		sort(t + 1, t + 1 + k, [](str a, str b) {return a.x > b.x; });
		long long ans = 0, cnt = 0;
		for (int i = 1; i <= k; ++i) {
		    if (t[i].x - cnt * 2 > 0) {
		      int num_tmp = max(1ll, t[i].x - cnt * 2 - 1);
			  ans += num_tmp;
		    }
		    cnt += 2;
		}
		printf("%lld\n", n - ans);
	}
}