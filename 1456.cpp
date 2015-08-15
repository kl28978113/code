#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, w;
		double sum[110] = {0}, DP[110][110] = {0}, total = 0;
		scanf("%d%d", &n, &w);
		for (int i = 1; i <= n; i++) {
			scanf("%lf", &sum[i]);
			total += sum[i];
		}
		sort(sum + 1, sum + n + 1, greater<double>());

		for (int i = 1; i <= n; i++)
			sum[i] = sum[i] / total + sum[i-1];

		for (int i = 1; i <= n; i++)  {
			DP[i][0] = 0x3f3f3f3f;
			for (int j = 1; j <= w; j++) {
				DP[i][j] = 0x3f3f3f3f;
				for (int k = 1; k <= i; k++)
					DP[i][j] = min(DP[i][j], DP[k-1][j-1] + i * (sum[i] - sum[k-1]));
			}
		}

		printf("%.4lf\n", DP[n][w]);
	}
	return 0;
}
