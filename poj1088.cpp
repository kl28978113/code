#include <cstdio>
#include <algorithm>
using  namespace std;

struct Point {
	int x, y, h;
	bool operator < (const Point a) const {
		return h < a.h;
	}
} A[10010];

int main() {
	int R, C, M[110][110][2];
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	while (scanf("%d%d", &R, &C) != EOF) {
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				scanf("%d", &M[i][j][0]);
				M[i][j][1] = 1;
				A[i*C+j].h = M[i][j][0];
				A[i*C+j].x = i;
				A[i*C+j].y = j;
			}

		sort(A, A + R*C);
		int ans = 1;
		for (int i = 0; i < R*C; i++) {
			int x = A[i].x, y = A[i].y;
			for (int j = 0; j < 4; j++) {
				int xx = x + dx[j], yy = y + dy[j];
				if (xx >= 0 && xx < R && yy >= 0 && yy < C && M[x][y][0] > M[xx][yy][0])
					M[x][y][1] = max(M[x][y][1], M[xx][yy][1] + 1);
			}
			ans = max(ans, M[x][y][1]);
		}

		printf("%d\n", ans);
	}
	return 0;
}
