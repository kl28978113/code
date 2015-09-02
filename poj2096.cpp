#include <cstdio>

double DP[1010][1010];
int n, s;

double DPS(int i, int j) {
	if (DP[i][j] > 0 || (n*s == i*j) || i > n || j > s)
		return DP[i][j];
	DP[i][j] = (DPS(i+1, j) * (n-i)*j + DPS(i, j+1) * i*(s-j) + DPS(i+1, j+1) * (n-i)*(s-j) + n*s) / (n*s - i*j);
	return DP[i][j];
}

int main() {
	while (scanf("%d%d", &n, &s) != EOF) {
		for (int i = 0; i <= n+5; i++)
			for (int j = 0; j <= n+5; j++)
				DP[i][j] = 0;

		printf("%.4f\n", DPS(0, 0));
	}
	return 0;
}
