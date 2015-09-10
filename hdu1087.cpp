#include <cstdio>

int main() {
	int N;
	while (scanf("%d", &N) && N) {
		int ans = 0, sum[1010] = {0}, A[1010];
		for (int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
			sum[i] = A[i];
			for (int j = 0; j < i; j++)
				if (A[j] < A[i] && sum[j] + A[i] > sum[i])
					sum[i] = sum[j] + A[i];
			if (sum[i] > ans) ans = sum[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
