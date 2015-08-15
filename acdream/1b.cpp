#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, A[30], B[30];
int d[30][30][30][30], v[30][30][30][30];

int DP(int L1, int R1, int L2, int R2) {
	if (v[L1][R1][L2][R2])
		return d[L1][R1][L2][R2];
	v[L1][R1][L2][R2] = 1;

	int sum = 0, ans = 0;
	if (L1 <= R1)
		sum += A[R1] - A[L1-1];
	if (L2 <= R2)
		sum += B[R2] - B[L2-1];

	if (L1 <= R1) {
		ans = max(ans, sum - DP(L1+1, R1, L2, R2));
		ans = max(ans, sum - DP(L1, R1-1, L2, R2));
	}
	if (L2 <= R2) {
		ans = max(ans, sum - DP(L1, R1, L2+1, R2));
		ans = max(ans, sum - DP(L1, R1, L2, R2-1));
	}

	return d[L1][R1][L2][R2] = ans;
}

int main() {
	while (scanf("%d", &n) != EOF) {
		memset(d, 0, sizeof(d));
		memset(v, 0, sizeof(v));
		for (int i = 1; i <= n; i++) {
			int tmp;
			scanf("%d", &tmp);
			A[i] = A[i-1] + tmp;
		}
		for (int i = 1; i <= n; i++) {
			int tmp;
			scanf("%d", &tmp);
			B[i] = B[i-1] + tmp;
		}

		printf("%d\n", DP(1, n, 1, n));
	}
	return 0;
}
