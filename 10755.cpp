#include <cstdio> include <algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int A, B, C;
		long long tmp, s[25][25][25] = {0};
		scanf("%d%d%d", &A, &B, &C);
		for (int i = 1; i <= A; i++)
			for (int j = 1; j <= B; j++)
				for (int k = 1; k <= C; k++) {
					scanf("%lld", &tmp);
					s[i][j][k] = s[i][j][k-1] + s[i][j-1][k] - s[i][j-1][k-1] + tmp;
				}

		long long ans = -0x3f3f3f3f3f3f3f;
		for (int m = 1; m <= B; m++)
			for (int n = m; n <= B; n++)
				for (int p = 1; p <= C; p++)
					for (int q = p; q <= C; q++) {
						long long MAX = 0;
						for (int x = 1; x <= A; x++) {
							long long sum = s[x][n][q] - s[x][m-1][q] - s[x][n][p-1] + s[x][m-1][p-1];
							MAX = max(MAX + sum, sum);
							ans = max(ans, MAX);
						}
					}
		printf("%lld\n", ans);
		if (T) printf("\n");
	}
	return
