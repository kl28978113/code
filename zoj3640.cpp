#include <cstdio>
#include <cmath>
#include <cstring>
double DP[20020];
int N, C[110], t[110];

double DPS(int f) {
	if (DP[f] > 0) return DP[f];

	for (int i = 0; i < N; i++)
		if (f > C[i])
			DP[f] += (1.0 / N) * t[i];
		else
			DP[f] += (1.0 / N) * (DPS(f + C[i]) + 1.0);

	return DP[f];
}

int main() {
	int f;
	while (scanf("%d%d", &N, &f) != EOF) {
		memset(DP, 0, sizeof(DP));
		double k = (1.0 + sqrt(5.0)) / 2;
		for (int i = 0; i < N; ++i) {
			scanf("%d", &C[i]);
			t[i] = int (k * C[i] * C[i]);
		}

		printf("%.3lf\n", DPS(f));
	}
	return 0;
}
