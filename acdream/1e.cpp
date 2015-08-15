#include <cstdio>

int DP[15][15];

int solve(int n) {
	int cnt = 0, ans= 0, num[15];
	while (n > 0) {
		num[++cnt] = n % 10;
		n /= 10;
	}
	 num[cnt+1] = 0;
	for (int i = cnt; i > 0; i--) {
		for (int j = 0; j < num[i]; j++) {
			if (j != 4 && !(num[i+1] == 3 && j == 7))
			ans += DP[i][j];
		}
		if (num[i] == 4 || (num[i] == 7 && num[i+1] == 3))
			break;
	}
	return ans;
}

int main() {
	int L, R;
	DP[0][0] = 1;
	for (int i = 1; i <= 10; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				if (j != 4 && !(j == 3 && k == 7))
					DP[i][j] += DP[i-1][k];

	while (scanf("%d%d", &L, &R) != EOF)
		printf("%d\n", solve(R+1) - solve(L));

	return 0;
}
