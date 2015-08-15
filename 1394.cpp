#include <cstdio>

int main() {
	int n, k, m, DP[10010];

	while (scanf("%d%d%d", &n, &k, &m) && n + k + m) {
		DP[1] = 0;
		for (int i = 2; i < n; i++)
			DP[i] = (DP[i-1] + k) % i;
		DP[n] =  (DP[n-1] + m) % n;
		printf("%d\n", DP[n] + 1);
	}
	return 0;
}
