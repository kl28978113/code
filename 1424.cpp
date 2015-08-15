#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n1, n2, DP[210][110], M[110][110] = {0};
		memset(DP, 0x3f3f3f3f, sizeof(DP));
		scanf("%d%d", &n1, &n2);
		for (int i = 1; i <= n1; i++) {
			M[i][i] = 1;
			DP[0][i] = 0;
		}

		int x, y;
		for (int i = 0; i < n2; i++) {
			scanf("%d%d", &x, &y);
			M[x][y] = M[y][x] = 1;
		}

		int n, A[210];
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &A[i]);

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n1; j++)
				for (int k = 1; k <= n1; k++) if (M[j][k])
					DP[i][j] = min(DP[i][j], DP[i-1][k] + (j != A[i]));

		int ans = n;
		for (int j = 1; j <= n1; j++)
			ans = min(ans, DP[n][j]);

		printf("%d\n", ans);
	}
	return 0;
}
