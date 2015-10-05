#include <cstdio>
#include <cstring>
long long DP[1010][1010];
long long MOD = 1e9 + 7;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(DP, 0, sizeof(DP));
		DP[0][0] = 1;
		int n;
		long long p, a;
		scanf("%d%lld", &n, &p);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a);
			a = (a % p + p) % p;

			for (int j = 0; j < p; j++) {
				long long tmp = DP[i-1][j];
				if (tmp) {
					DP[i][j] = (DP[i][j] + tmp) % MOD;
					// printf("a = %lld, tmp = %lld, ", a, tmp);
					DP[i][(j + a) % p] = (DP[i][(j + a) % p] + tmp) % MOD;
				//	printf("DP[%d][%lld] = %lld\n", i, (j + a) %p, DP[i][(j + a)%p]);
				}
			}
		////	DP[i][a] = (DP[i][a] + 1) % MOD;
		}
		printf("%lld\n", DP[n][0]);
	}
	return 0;
}
