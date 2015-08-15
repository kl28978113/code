#include <cstdio>


int main() {
	int sum, A[100];
	for (int n = 1; n <= 60; n++) {
		sum = n;
		for (int i = 3; i <= n; i += 3)
			sum += ((n - i) + 1) * ((n - i)) / 2;
		A[n] = sum;
	}

	int tmp;
	while (scanf("%d", &tmp) != EOF) {
		printf("%d\n", A[tmp]);
	}

	return 0;
}
