#include <cstdio>

int main() {
	int n, tmp, flag = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		flag += (tmp == 1);
	}
	flag ? puts("-1") : puts("1");
	return 0;
} 
