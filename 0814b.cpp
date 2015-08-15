#include <cstdio>

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	if (n - m > m - 1)
		printf("%d\n", m + 1);
	else if(n != 1)
		printf("%d\n", m - 1);
	else 
		printf("1\n");
	return 0;
}
