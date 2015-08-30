#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M, DP[2010] = {0};
		scanf("%d%d", &M, &N);
		for (int r = 1; r <= N; r++) {
			int W, A, B, flag = 0, tmp;
			scanf("%d%d%d", &W, &A, &B);
			for (int i = W; i <= M; i++) {
				if (flag == 0 || i < flag + W) {
					if (DP[i-W] + A + B > DP[i]) {
						DP[i] = DP[i-W] + A + B;
						if (flag == 0)
							flag = i;
					}
				} else if (DP[i-W] + A > DP[i]) {
					DP[i] = A + DP[i-W];
				}
			}
		}
		printf("%d\n", DP[M]);
	}
	return 0;
}
