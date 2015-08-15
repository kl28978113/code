#include <cstdio>

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int A[10100] = {0}, tmp, MAX = 0, MAX_X;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &tmp);
			A[tmp]++;
			if (A[tmp] > MAX) {
				MAX = A[tmp];
				MAX_X = tmp;
			}
		}
		if (2 * MAX > n) printf("%d\n", MAX_X);
		else puts("-1");
	}
	return 0;
}
