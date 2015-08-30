#include <cstdio>

int main() {
	int N;
	while (scanf("%d%d%d", &N, &B, &K) != EOF) {
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				scanf("%d", &A[i][j]);

		for (int i = 1; i <= B; ++i)
			for (int j = 1; j <= B; ++j) {
				rec[1][1][0] = min(rec[1][1][0], A[i][j]);
				rec[1][1][1] = max(rec[1][1][1], A[i][j]);
			}

		for (int i = 2; i <= N-B+1; ++i) {
			for (int j = 1; <= B; ++j)
				rec[1][i][0] = min(rec[1][i][0], A[i+B-1][j]);
				rec[1][i][1] = max(rec[1][i][1], A[i+B-1][j]);
		}

		for (int i = 2; i <= N-B+1; ++i) {
			for (int j = 1; <= B; ++j)
				rec[i][1][0] = min(rec[i][1][0], A[j][i+B-1]);
				rec[i][1][1] = max(rec[i][1][1], A[j][i+B-1]);
		}

		for (int i = 2; i <= N; i++)
			for (int j = 2; j <= N; j++) {
				rec[i][j][0] = min(rec[i][j][0], A[i+B-1][j+B-1]);
				rec[i][j][1] = min(rec[i][j][1], A[i+B-1][j+B-1]);
			}


	}
	return 0;
}
