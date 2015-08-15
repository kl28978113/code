#include <cstdio>

int main() {
	int n, m, pos, cur = 0, ans = 0;
	char A[300010], c[10];
	scanf("%d%d%s", &n, &m, A + 1);
	A[n + 1] = A[0] = 'a';

	for (int i = 1; i <= n + 1; i++)
		if (A[i] != '.') {
		//	printf("i = %d, ", i);
			if (i - cur - 1)
				ans += i - cur - 1 - 1;
			cur = i;
		}
	//printf("%d\n", ans);
	for (int i = 0; i < m; i++) {
		scanf("%d%s", &pos, c);
		if (c[0] != '.') {
			if (A[pos] == '.') {
				if (A[pos-1] == '.')
					ans--;
				if (A[pos+1] == '.')
					ans--;
			}
		} else {
			if (A[pos] != '.') {
				if (A[pos-1] == '.')
					ans++;
				if (A[pos+1] == '.')
					ans++;
			}
		}
		A[pos] = c[0];
		printf("%d\n", ans);
	}

	return 0;
}
