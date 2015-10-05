#include <cstdio>

int main() {
	long long n, x; 
	int	cnt = 0; 
	scanf("%lld%lld", &n, &x);
	for (long long i = 1; i <= n; i++) {
		if (x % i == 0 && x <= n * i)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
