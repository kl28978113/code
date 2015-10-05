#include <cstdio>
#include <cstring>

int R[100010], C[100010];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, K, Q;
		scanf("%d%d%d%d", &n, &m, &K, &Q);
		memset(R, 0, sizeof(int) * (n+5));
		memset(C, 0, sizeof(int) * (m+5));
		int x, y;
		for (int i = 0; i < K; i++) {
			scanf("%d%d", &x, &y);
			R[x] = 1;
			C[y] = 1;
		}
		for (int i = 1; i <= n; i++)
			R[i] += R[i-1];

		for (int i = 1; i <= m; i++)
			C[i] += C[i-1];

		int x1, y1, x2, y2;
		for (int i = 0; i < Q; i++) {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2); 
			if (R[x2] - R[x1-1] == x2 - x1 + 1 || C[y2] - C[y1-1] == y2 - y1 + 1)
				puts("Yes");
			else
				puts("No");
		}
	}
	return 0;
}
