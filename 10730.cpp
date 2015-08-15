#include <cstdio>

int main() {
	int n, tmp, A[10010];
	while (scanf("%d%*c", &n) && n) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			A[tmp] = i;
		}

		for (int i = 0; i < n; i++)
			for (int j = 1; i + j + j < n; j++)
				if (A[i] < A[i+j] && A[i+j] < A[i+j+j]) {
					puts("no");
					goto flag;
				}
		puts("yes");
flag:;
	}
	return 0;
}
