#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N, A[110][110] = {0};
	while (scanf("%d", &N) != EOF) {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				scanf("%d", &A[i][j]);
				A[i][j] += A[i-1][j];
			}

		int ans = -0x3f3f3f3f;
		for (int i = 0; i < N; i++)
			for (int j = i + 1; j <= N; j++) {
				int cur = 0;
				for (int k = 1; k <= N; k++) {
					cur = max(cur, 0);
					cur += A[j][k] - A[i][k];
					ans = max(cur, ans);
				}
			}

		printf("%d\n", ans);
	}
	return 0;
}
