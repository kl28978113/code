#include <cstdio>
#include <cstring>

int A[100010], N, M;
double DP[100010];

double DPS(int pos) {
	if (DP[pos] != 0)
		return DP[pos];

	if (pos >= N)
		return 0;

	if (A[pos])
		DP[pos] = DPS(A[pos]);
	else for (int i = 1; i <= 6; ++i)
		DP[pos] += (DPS(pos + i) + 1) / 6;


	return DP[pos];
}


int main() {
	while (scanf("%d%d", &N, &M) && N) {
		memset(DP, 0, sizeof(DP));
		memset(A, 0, sizeof(A));
		for (int i = 0; i < M; ++i) {
			int X, Y;
			scanf("%d%d", &X, &Y);
			A[X] = Y;
		}

		for (int i = N-1; i >= 0; i--) {
			if (A[i])
				DP[i] = DP[A[i]];
			else for (int j = 1; j <= 6; j++)
				DP[i] += (DP[i+j] + 1) / 6;
		}

		printf("%.4lf\n", DP[0]); 

	}
	return 0;
}
