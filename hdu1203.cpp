#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) && n + m) {
		double DP[10010];
		for (int i = 0; i <= n; i++)
			DP[i] = 1.0;

		while (m--) {
			int A;
			double B;
			scanf("%d%lf", &A, &B);
			B = 1 - B;
			for (int i = n; i >= A; i--)
				DP[i] = min(DP[i], DP[i-A]*B);
		}
		printf("%.1lf%%\n", (1 - DP[n]) * 100);
	}
	return 0;
}
