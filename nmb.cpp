#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N, M, K;
	while (scanf("%d%d%d", &N, &M, &K) != EOF) {
		long long DP[1010][15] = {0}, ans = 0;
		int V, W;
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &V, &W);
			for (int j = M; j >= 0; j--)
				for (int k = K; k >= 0; k--) {
					if (j >= V)
						DP[j][k] = max(DP[j-V][k] + W, DP[j][k]);
					if (k >= 1)
						DP[j][k] = max(DP[j][k-1] + W, DP[j][k]);

					ans = max(ans, DP[j][k]);
				}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
