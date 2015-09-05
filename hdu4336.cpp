#include <cstdio>

double DP[(1<<20) + 5], P[25];

int main() {
	int N;
	while (scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; i++)
			scanf("%lf", &P[i]);

		int MAX = (1 << N) - 1;
		DP[MAX] = 0;
		for (int i = MAX - 1; i >= 0; i--) {
			double sum = 0;
			DP[i] = 1;
			for (int j = 0; j < N; j++) {
				if (i & (1 << j)) continue;
				DP[i] += DP[i | (1 << j)] * P[j]; 
				sum += P[j];
			}
			DP[i] /= sum;
		}

		printf("%.3f\n", DP[0]);
	}
	return 0;
}
