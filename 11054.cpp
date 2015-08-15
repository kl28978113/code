#include <cstdio>

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		long long ans = 0, cur = 0, tmp;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &tmp);
			cur += tmp;
			ans += cur > 0 ? cur : -cur;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
