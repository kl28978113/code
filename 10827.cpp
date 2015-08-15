#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T, N, A[160][160], DP[160][160] = {0};
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			for (int j = 0; j < N; j++) {
				scanf("%d", &A[i][j]);
				A[i+N][j] = A[i][j]; 
			}

		for (int i = 1; i <= 2 * N; i++)
			for (int j = 0; j < N; j++)
				DP[i][j] = DP[i][j+N] = DP[i-1][j] + A[i][j];

		int ans = 0;
		for (int i = 0; i < N; i++)
			for (int j = i + 1; j - i <= N; j++)
				for (int k = 0; k < N; k++) {
					int  cur = 0;
					for (int l = k; l - k < N; l++) {
						cur += DP[j][l] - DP[i][l];
						ans = max(ans, cur);
					}
				}

		printf("%d\n", ans);
	}
	return 0;
}
