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
				DP[i][j] = DP[i-1][j] + A[i][j];

		int ans = 0;
		for (int i = 0; i < N; i++)
			for (int j = i + 1; j - i <= N; j++) {
				int MIN = 0, MAX = 0, sum = 0, t1 = 0, t2 = 0;
				for (int k = 0; k < N; k++) { 
					int tmp = DP[j][k] - DP[i][k];
					sum += tmp;
					if (t1 <= 0)
						t1 = tmp;
					else
						t1 += tmp;

					if (t2 >= 0)
						t2 = tmp;
					else
						t2 += tmp;

					MIN = min(t2, MIN);
					MAX = max(t1, MAX);
				}
				ans = max(ans, max(sum - MIN, MAX));
			}

		printf("%d\n", ans);
	}
	return 0;
}
