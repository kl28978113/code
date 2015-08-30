#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N;
	while (scanf("%d", &N) != EOF) {
		int DP[110][110];
		for (int i = 0; i < N; i++)
			for (int j = 0; j <= i; j++)
				scanf("%d", &DP[i][j]);
		for (int i = N-2; i >= 0; i--)
			for (int j = 0; j <= i; j++)
				DP[i][j] += max(DP[i+1][j], DP[i+1][j+1]);

		printf("%d\n", DP[0][0]);
	}
	return 0;
}

