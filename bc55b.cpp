#include <cstdio>
#include <cstring>


int x1, y1, x2, y2, k, n, m, vis[60][60];
char A[60][60];
double MIN, DP[60][60][60];

int dx[5] = {1, -1, 0, 0};
int dy[5] = {0, 0, 1, -1};

double DFS(int x, int y, int cur) {
	if (DP[x][y][cur] != 0x3f3f3f3f)
		return DP[x][y][cur];

	if (cur >= k)
		return 0x3f3f3f3f;

	if (x == x2 && y == y2) {
		return 0;
	}

	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 0 && tx < n && ty >= 0 && ty < m && A[tx][ty] != '#' && !vis[tx][ty]) {
			vis[tx][ty] = 1;
			double tmp = DFS(tx, ty, cur + 1) + 1.0 * (A[tx][ty] > A[x][y] ? A[tx][ty] - A[x][y] : A[x][y]-A[tx][ty])/(k - cur);
			DP[x][y][cur] = DP[x][y][cur] < tmp ? DP[x][y][cur] : tmp;
			vis[tx][ty] = 0;
		}
	}
	return DP[x][y][cur];
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		MIN = 0x3f3f3f3f;
		memset(vis, 0, sizeof(vis));
		scanf("%d%d%d", &n, &m, &k);

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				for (int r = 0; r <= k; r++)
					DP[i][j][r] = 0x3f3f3f3f;

		for (int i = 0; i < n; i++)
			scanf("%s", A[i]);
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1 -= 1, y1 -= 1, x2 -= 1, y2 -= 1;
		int flag = 0;

		flag += x1 > x2 ? x1 - x2 : x2 - x1;
		flag += y1 > y2 ? y1 - y2 : y2 - y1;

		double ans = 0x3f3f3f3f;
		if (flag < k)
			ans = DFS(x1, y1, 0);
		if (ans == 0x3f3f3f3f)
			puts("No Answer");
		else
			printf("%.2lf\n", ans);
	}
	return 0;
}
