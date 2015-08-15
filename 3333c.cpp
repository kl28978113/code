#include <cstdio>
const int MOD = 258280327;
int C[100010], DP[100010][10];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, A, B, ans = 0, sum = 0;
		scanf("%d%d%d", &N, &A, &B);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &C[i]);
			sum += C[i];
		}

		if ((A + B) % 9 != sum % 9) {
			if (A % 9 == sum % 9 || B % 9 == sum % 9)
				ans++;
			printf("%d\n", ans);
			continue;
		}

		DP[0][0] = 1;
		for (int i = 1; i <= N; i++)
			for (int j = 0; j < 9; j++)
				DP[i][j] = (DP[i-1][j] + DP[i-1][(j - C[i] + 9) % 9]) % MOD;

		printf("%d\n", DP[N][A % 9]);
	}
}
