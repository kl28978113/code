#include <cstdio>
#include <algorithm>
using namespace std;

struct Tree {
	int a, b;
	bool operator < (Tree x) const {
		if (b != x.b)
			return b < x.b;
		return a > x.a;
	}
} T[260];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d", &T[i].a);
		for (int i = 1; i <= n; i++)
			scanf("%d", &T[i].b);

		int DP[260][260] = {0};
		sort(T+1, T+1+n);
		// for (int i = 1; i <= n; i++)
			// printf("(%d,%d)  ", T[i].a, T[i].b);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++) {
				DP[i][j] = max(DP[i-1][j], DP[i-1][j-1] + T[i].a + T[i].b * (j-1) );

				// printf("DP[%d][%d] = %d, \n", i, j, DP[i][j]);
			}
		printf("%d\n", DP[n][m]);
	}
	return 0;
}
