#include <cstdio> 
#include <cmath>

int main() {
	long long DP[15][15] = {1};
	for (int i = 1; i < 8; i++) {
		long long tmp = 0;
		for (int j = 0; j < 10; j++) {
			tmp += DP[i-1][j];
		}
		for (int j = 0; j < 10; j++)
			DP[i][j] = tmp;
		DP[i][6] -= DP[i-1][2];
		DP[i][4] = 0;
	}

	int n, m;
	while (scanf("%d%d", &n, &m) && n + m) {
		long long sum1 = 0, sum2 = 0;
		int cnt1 = 0, cnt2 = 0;
		int tmp = 10;
		int  num1[10] = {0}, num2[10] = {0};
		m++;
		while (n > 0) {
			num1[++cnt1] = n % 10;
			n /= 10;
		}

		while (m > 0) {
			num2[++cnt2] = m % 10;
			m /= 10;
		}

		while (cnt1 > 0) {
			for (int i = 0; i < num1[cnt1]; i++) {
				if (i == 4 || (i == 2 && num1[cnt1+1] == 6)) continue;
				sum1 += DP[cnt1][i];
			}
			if ((num1[cnt1] == 2 && num1[cnt1+1] == 6) || num1[cnt1] == 4) break;
			cnt1--;
		}

		while (cnt2 > 0) {
			for (int i = 0; i < num2[cnt2]; i++) {
				if (i == 4 || (i == 2 && num2[cnt2+1] == 6)) continue;
				sum2 += DP[cnt2][i];
			}
			if ((num2[cnt2] == 2 && num2[cnt2+1] == 6) || num2[cnt2] == 4) break;
			cnt2--;
		}
		printf("%lld\n", sum2 - sum1);
	}
	return 0;
}
