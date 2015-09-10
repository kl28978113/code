#include <cstdio>
#include <algorithm>
using namespace std;

struct Mouse {
	int m, s, ID;
	bool operator < (Mouse a) const {
		if (m != a.m)
			return m > a.m;
		return s < a.m;
	}
} A[1010];

int main() {
	int pos, n = 0, ans = 0, pre[1010], DP[1010];
	while (scanf("%d%d", &A[n].m, &A[n].s) != EOF) {
		A[n].ID = n + 1;
		n++;
	}
	sort(A, A + n);

	for (int i = 0; i < n; i++) {
		DP[i] = 1;
		for (int j = 0; j < i; j++)
			if (A[j].m > A[i].m && A[j].s < A[i].s && DP[i] < DP[j] + 1) {
				DP[i] = DP[j] + 1;
				pre[i] = j;
			}
		if (ans < DP[i]) {
			ans = DP[i];
			pos = i;
		}
	}
	printf("%d\n%d\n", ans, A[pos].ID);
	while (--ans) {
		printf("%d\n", A[pre[pos]].ID);
		pos = pre[pos];
	}
	return 0;
}
