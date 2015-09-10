#include <cstdio>

int main() {
	int n, M;
	while (scanf("%d%d", &n, &M) != EOF) {
		long long sum = 0, ans = 0, C;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &C);
			if ((sum + C)*(sum + C) + M > sum * sum + C * C + 2 * M ) {
				ans += sum * sum + M;
				sum = C;
			} else
				sum += C;
		}

		ans += sum * sum + M;
		printf("%lld\n", ans);
	}
	return 0;
}
