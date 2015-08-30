#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int DP[2][1200], B[110][110], P[110][110], m[110];

int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int MAX = 0, MIN = 0x3f3f3f3f;
		for (int i = 0; i < n; i++) {
			scanf("%d", &m[i]);
			for (int j = 0; j < m[i]; j++) {
				scanf("%d%d", &B[i][j], &P[i][j]);
				MAX = max(MAX, B[i][j]);
				MIN = min(MIN, B[i][j]);
			}
		}

		int cur = 1, pre = 0;
		memset(DP[pre], 0x3f3f3f3f, sizeof(int) * (MAX + 1));
		for (int j = 0; j < m[0]; j++)
			DP[pre][B[0][j]] = P[0][j];

		for (int i = 1; i < n; i++) {
			memset(DP[cur], 0x3f3f3f3f, sizeof(int) * (MAX + 1));
			for (int j = 0; j < m[i]; j++)  {
				for (int k = MIN; k <= MAX; k++)
					if (k <= B[i][j]) 
						DP[cur][k] = min(DP[cur][k], DP[pre][k] + P[i][j]);
					else 
						DP[cur][B[i][j]] = min(DP[cur][B[i][j]], DP[pre][k] + P[i][j]);
			}
			swap(cur, pre);
		}

		double ans = 0;
		for (int k = MIN; k <= MAX; k++)
			if (DP[pre][k] != 0x3f3f3f3f)
				ans = max(ans, 1.0 * k / DP[pre][k]);

		printf("%.3f\n", ans);
	}
	return 0;
}
