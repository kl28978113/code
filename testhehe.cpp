#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, A[32][32], ans;
int DP[32][32][1835];


int main() {
	for (int i = 0; i <= 30; i++)
		for (int k = 0; k <= 1830; k++)
			DP[i][0][k] = DP[0][i][k] = 0x3f3f3f3f;

	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		memset(DP, 0x3f3f3f3f, sizeof(DP));
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				scanf("%d", &A[i][j]);

		DP[1][1][0] = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++) {
				int MAX = (i + j - 1) * 30;
				for (int k = 0; k <= MAX; k++)
					if (DP[i][j][k] != 0x3f3f3f3f) {
						DP[i+1][j][k + A[i][j]] = min(DP[i+1][j][k+A[i][j]], DP[i][j][k] + A[i][j] * A[i][j]);
						DP[i][j+1][k + A[i][j]] = min(DP[i][j+1][k+A[i][j]], DP[i][j][k] + A[i][j] * A[i][j]);
					}
			}

		int ans = 0x3f3f3f3f;
		for (int k = 0; k <= 1830; k++)
			if (DP[N][M][k] != 0x3f3f3f3f)
				ans = min(ans, (N + M - 1) * (DP[N][M][k] + A[N][M] * A[N][M])- (k + A[N][M])* (k+A[N][M]));

		printf("Case #%d: %d\n", ++kase, ans);
	}
	return 0;
}
