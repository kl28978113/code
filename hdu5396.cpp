#include <cstdio>

int main() {
	const long long MOD = 1e9 + 7;
	long long C[105][105]; 
	for (int i = 0; i <= 100; i++)
		C[i][0] = 1;
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= i; j++) 
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;

	long long F[105] = {1};
	for (int i = 1; i <= 100; i++) 
		F[i] = (i * F[i-1]) % MOD;

	int n;
	char op[105];
	while (scanf("%d", &n) != EOF) {
		long long DP[105][105] = {0};
		for (int i = 1; i <= n; i++)
			scanf("%lld", &DP[i][i]);
		scanf("%s", op + 1);

		for (int l = 1; l <= n-1; l++)
			for (int i = 1; i <= n-l; i++){
				int j = i + l;
				for (int k = i; k < j; k++) {
					long long tmp = 0;
					if (op[k] == '*')
						tmp = (DP[i][k] * DP[k+1][j]) % MOD; 
					else if (op[k] == '+')
						tmp = (F[j-k-1] * DP[i][k] + F[k-i] * DP[k+1][j]) % MOD;
					else
						tmp = (F[j-k-1] * DP[i][k] - F[k-i] * DP[k+1][j]) % MOD;

					DP[i][j] = (DP[i][j] + tmp * C[j-i-1][k-i]) % MOD;
				}
			}
		printf("%lld\n", (DP[1][n] + MOD) % MOD);
	}

	return 0;
}
