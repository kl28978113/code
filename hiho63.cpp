#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1 << 12;
int DP[MAXN][15], Map[15][15];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int x, y;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		x--, y--;
		Map[x][y] = 1;
	}

	DP[1][0] = 1;
	int MAX = (1 << n) - 1;
	for (int i = 1; i <= MAX; i++) {
		for (int j = 0; j < n; j++) {
			int s = (1 << j) ^ i;
			if ((1 << j) & i) for (int r = 0; r < n; r++)
				if (((1 << r) & s) && Map[r][j]) {
					DP[i][j] += DP[s][r];
				}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (Map[i][0])
			ans +=  DP[MAX][i];
	printf("%d\n", ans);
	return 0;
}
