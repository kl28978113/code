#include <cstdio>

int main() {
	int t;
	scanf("%d", &t);
	int n, k;
	while (t--) {
		scanf("%d%d", &n, &k);
		if (n <= k || ( k == 1 && n % 2))
			puts("Alex");
		else
			puts("Asd");
	}
	return 0;
}
