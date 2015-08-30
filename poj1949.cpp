#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int N, A[10010][105], T[10010], E[10010];

int DPS(int x) {
	if (E[x])
		return E[x];

	for (int i = 1; i <= A[x][0]; ++i)
		E[x] = max(E[x], DPS(A[x][i]) + T[x]);

	return E[x];
}

int main() {
	while (scanf("%d", &N) != EOF) {
		memset(E, 0, sizeof(E));
		for (int i = 1; i <= N; ++i) {
			scanf("%d%d", &T[i], &A[i][0]);
			for (int j = 1; j <= A[i][0]; ++j)
				scanf("%d", &A[i][j]);
		}

		int ans = 0;
		for (int i = 1; i <= N; ++i) {
			E[i] = A[i][0] ? DPS(i) : T[i];
			ans = max(ans, E[i]);
		}

		printf("%d\n", ans);
	}
	return 0;
}
