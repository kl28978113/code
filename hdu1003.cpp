#include <cstdio>

int main () {
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		int n, tmp, ans = -0x3f3f3f3f, sum = 0, L = 1, R = 1, ans_L = 1, ans_R = 1;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &tmp);
			if (ans < sum + tmp) {
				ans = sum + tmp;
				ans_L = L;
				ans_R = i;
			}
			sum += tmp;
			if (sum < 0) { 
				sum = 0;
				L = i + 1;
			}

		}
		printf("Case %d:\n%d %d %d\n", ++kase, ans, ans_L, ans_R);
		if (T) puts("");
	}
	return 0;
}
