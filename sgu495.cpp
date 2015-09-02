#include <cstdio>
double DP[100010] = {1}, ans = 1;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 1; i < M; i++) {
		DP[i] = (1.0 - DP[i-1]) * DP[i-1] + DP[i-1] * (DP[i-1] - 1.0/N);
		ans += DP[i];
	}
	printf("%.10lf\n", ans);
	return 0;
}
