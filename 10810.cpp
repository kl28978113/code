#include <cstdio>

int A[500010], T[500010];
long long ans;

void merge_sort(int* A, int x, int y, int* T) {
	if (y - x > 1) {
		int m = x + (y - x) / 2;
		int p = x, q = m, i = x;
		merge_sort(A, x, m, T);
		merge_sort(A, m, y, T);
		while (p < m || q < y) {
			if (q >= y || (p < m && A[p] <= A[q])) T[i++] = A[p++];
			else T[i++] = A[q++], ans += m - p;
		}
		for (i = x; i < y; i++) A[i] = T[i];
	}
}

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		ans = 0;
		merge_sort(A, 0, n, T);
		printf("%lld\n", ans);
	}
	return 0;
}
