#include <cstdio>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);

	int n = a / b;
	if (n == 0) {
		puts("-1");
		return 0;
	}
	int MAX = a + b;
	if (n % 2)
		n++;
	double ans = 1.0 * MAX / n;
	printf("%.12lf\n", ans);
	return 0;
}
