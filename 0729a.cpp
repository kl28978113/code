#include <cstdio>

int main() {
	long long  n;
	while (scanf("%lld", &n) != EOF) {
		long long tmp, sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &tmp);
			sum += tmp;
		}
		printf("%lld\n", n -  (sum % n != 0));
	}
	return 0;
}

