#include <cstdio>

int main() {
	int DP[15][15] = {0};
	for (int i = 2; i <= 10; i++) {
		int tmp = 0;
		for (int j = 0; j < 10; j++)
		DP[i][1] = 1;
		for (int j = 0; j < 10; j++) {
			DP[i][j] += tmp;
			printf("DP[%d][%d] = %d, \n", i, j, DP[i][j]);
		}
	}

	int n;
	while (scanf("%d", &n) != EOF) {
		int cnt = 1, num[15];
		n++;
		while (n) {
			num[cnt++] = n % 10;
			n /= 10;
		}

		//printf("%d\n", cnt);
		int sum = 0;
		while (--cnt) {
			for (int i = 0; i < num[cnt]; i++)
				sum += DP[cnt][i];
			if (num[cnt+1] == 1 && num[cnt] >= 3)
				sum += 1;
		}
		printf("%d\n", sum);
	}
	return 0;
}
