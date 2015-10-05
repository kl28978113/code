#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = (1 << 18);
long long DP[MAXN][20], R[20][20], A[20];

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld", &A[i]);
	int x, y;
	long long c;
	for (int i = 1; i <= k; i++) {
		scanf("%d%d%lld", &x, &y, &c);
		R[x-1][y-1] = c;
	}
	int MAX = (1 << n) - 1;
	long long ans = 0;
	for (int i = 0; i < n; i++)
		DP[1 << i][i] = A[i];
	for (int i = 1; i <= MAX; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			int s = i ^ (1 << j);
			if (i & (1 << j)) {
				cnt++;
				for (int r = 0; r < n; r++)
					if (s & (1 << r))
						DP[i][j] = max(DP[i][j], DP[s][r] + A[j] + R[r][j]);
			}
		}

		if (cnt == m) for (int j = 0; j < n; j++)
			ans = max(ans, (long long)DP[i][j]);
	}
	printf("%lld\n", ans);
	return 0;
}
