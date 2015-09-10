#include <cstdio>

int main() {
	int n, DP[25][200] = {1};
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= i; j++)
			for (int k = 0; k <= 190; k++)
				if (DP[i-j][k])
					DP[i][j*(i-j)+k] = 1;

	while (scanf("%d", &n) != EOF) {
		printf("0");
		for (int i = 1; i <= 190; i++)
			if (DP[n][i])
				printf(" %d", i);
		puts("");
	}
	return 0;
}
