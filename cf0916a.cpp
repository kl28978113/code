#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	int cnt = 0;
	while (n) {
		if (n % 2) {
			cnt++;
		}
		n /= 2;
	}
	printf("%d\n", cnt);
}
