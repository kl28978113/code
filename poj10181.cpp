#include <cstdio>
#include <algorithm>
using namespace std;

struct De{
	int B;
	int P;
	double R;
} DP[2][110];

int main() {
	int T, n, m;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		int B, P;
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &B, &P);
			DP[0][i].B = B;
			DP[0][i].P = P;
			DP[0][i].R = 1.0 * B / P;
		}

		int cnt = m, cur = 1, pre = 0;
		for (int i = 1; i < n; i++) {
			scanf("%d", &m);
			for (int j = 0; j < m; j++) {
				scanf("%d%d", &B, &P);
				DP[cur][j].R = 0;
				for (int k = 0; k < cnt; k++) {
					double tmp = 1.0 * min(DP[pre][k].B, B) / (DP[pre][k].P + P);
					if (tmp > DP[cur][j].R) {
						DP[cur][j].B = min(DP[pre][k].B, B);
						DP[cur][j].P = DP[pre][k].P + P;
						DP[cur][j].R = tmp;
					}
				}
			}
			swap(cur, pre);
			cnt = m;
		}

		double ans = 0;
		for (int i = 0; i < m; i++)
			ans = max(ans, DP[pre][i].R);

		printf("%.3f\n", ans);
	}
	return 0;
}
