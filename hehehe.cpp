#include <cstdio>

int main() {
	int N, k;
	while (scanf("%d%d", &N, &k) && (N + k)) {
		if ((N - 1) % (k + 1))
			puts("Tang");
		else
			puts("Jiang");
	}
	return 0;
}
