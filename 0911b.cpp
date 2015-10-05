#include <cstdio>

int main() {
	int n, rec[1010], cnt = 0, v[1010] = {0};
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) if (!v[i])
		for (int j = i * i; j <= n; j += i)
			v[j] = 1;

	for (int i = 2; i <= n; i++) if (!v[i]) 
		for (int j = i; j <= n; j *= i)
			rec[cnt++] = j;

	printf("%d\n", cnt);
	for (int i = 0; i < cnt-1; ++i) {
		printf("%d ", rec[i]);
	}
	if (cnt != 0)
		printf("%d\n", rec[cnt-1]);
	return 0;
}
