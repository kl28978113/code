#include <cstdio>
#include <cstring>

double DP[45][40005];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, MAX, tmp;  
		double P;
		scanf("%d%lf", &N, &P);

		memset(DP, 0, sizeof(DP));
		DP[0][0] = 1;
		MAX = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &tmp);
			for (int j = 0; j <= MAX; j++)
				if (DP[i][j] > 0) {
					DP[i + 1][j] += DP[i][j] * 0.5;
					DP[i + 1][j + tmp] += DP[i][j] * 0.5;
				}
			MAX += tmp;
		}

		double sum = 0;
		for (int j = 0; j <= MAX; j++) {
			sum += DP[N][j];
			if (sum >= P) {
				printf("%d\n", j);
				break;
			}
		}
	} 
	return 0;
}


