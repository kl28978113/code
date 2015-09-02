#include <cstdio>
#include <algorithm>
using namespace std;

int rec[255][255][2], ans[255][255][2], A[255][255];

int main() {
	int N, B, K;
	while (scanf("%d%d%d", &N, &B, &K) != EOF) {
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				scanf("%d", &A[i][j]);

		for (int i = 1; i <= N-B+1; ++i)
			for (int j = 1; j <= N; ++j) {
				rec[i][j][0] = 0x3f3f3f3f;
				rec[i][j][1] = -0x3f3f3f3f;
				for (int h = i; h < i+B; ++h){
					rec[i][j][0] = min(rec[i][j][0], A[h][j]);
					rec[i][j][1] = max(rec[i][j][1], A[h][j]);
				}
			}

		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N-B+1; ++j) {
				ans[i][j][0] = 0x3f3f3f3f;
				ans[i][j][1] = -0x3f3f3f3f;
				for (int h = j; h < j+B; ++h) {
					ans[i][j][0] = min(ans[i][j][0], rec[i][h][0]);
					ans[i][j][1] = max(ans[i][j][1], rec[i][h][1]);
				}
			}

		int x, y;
		for (int i = 0; i < K; i++) {
			scanf("%d%d", &x, &y);
			printf("%d\n", ans[x][y][1]-ans[x][y][0]);
		}
	}
	return 0;
}
