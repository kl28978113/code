#include <cstdio>

int main() {
	int n, m, A[110] = {0};
	scanf("%d%d", &n, &m);
	int MAXN = -1, ans = 1;
	for (int i = 1; i <= m; i++) {
		int tmp, MAX = -1, ID = 1;
		for (int j = 1; j <= n; j++) {
			scanf("%d", &tmp);
			if (tmp > MAX) {
				MAX = tmp;
				ID = j;
			}
		}
		A[ID]++;
	}

	for (int i = 1; i <= 100; i++)
	//	printf("%d")
		if (A[i] > MAXN) {
			MAXN = A[i];
			ans = i;
		}
	printf("%d\n", ans);

	return 0;
}
