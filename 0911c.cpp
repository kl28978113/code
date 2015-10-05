#include <cstdio>

int main() {
	int n, m, DP[1010][1010] = {0}, A[1000010];
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		A[i] %= m;
	}
	if (n >= m) {
		puts("YES");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		DP[i][A[i]] = 1;
		for (int j = 0; j < m; j++)
			if (DP[i-1][j])
				DP[i][j] = DP[i][(j+A[i])%m] = 1;
	}

	DP[n][0] ? puts("YES") : puts("NO");

	return 0;
}
