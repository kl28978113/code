#include <cstdio>
#include <cmath>

int main() {
	int T;
	long long m, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &m);
		n = (long long) (sqrt((m-1) / 3.0)) + 1;
		while (3 * n * (n-1) + 1 > m) n--;
		//printf("%lld\n", n);
		long long ans = 0, tmp;
		if (m % (3 * n * (n-1) + 1) == 0)
			printf("%d")


		while (m > 0) {
			//printf("%lld\n", m);
			tmp = 3 * n * (n-1) + 1;
			n--;
			ans += m / tmp;
			m %= tmp;
		}
		printf("%lld\n",ans);

	}
	return 0;
}
