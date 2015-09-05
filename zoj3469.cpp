#include <cstdio>
#include <algorithm>
using namespace std;

int DP[1010][1010][2];

struct Node {
	int x, b;
	bool operator < (Node a) const {
		return x < a.x;
	}
} A[1010];

int main() {
	int N, V, X;
	while (scanf("%d%d%d", &N, &V, &X) != EOF) {
		for (int i = 1; i <= N; i++)
			scanf("%d%d", &A[i].x, &A[i].b);
		N++;
		A[N].x = X;
		A[N].b = 0;

		sort(A + 1, A + N + 1);
		int sum[1010] = {A[0].b};

		for (int i = 1; i <= N; i++)
			sum[i] = sum[i-1] + A[i].b;
		for (int i = 1; i <= N; i++)
			for (int j = i; j <= N; j++)
				DP[i][j][0] = DP[i][j][1] = 0x3f3f3f3f;

		int tmp;
		for (int i = 1; i <= N; i++)
			if (A[i].x == X)
				tmp = i;

		DP[tmp][tmp][0] = DP[tmp][tmp][1] = 0;
		for (int i = tmp; i >= 1; i--)
			for (int j = tmp; j <= N; j++)  {
				if (i == j) continue;
				DP[i][j][0] = min(DP[i][j][0], DP[i+1][j][1] + (sum[i] + sum[N] - sum[j]) * (A[j].x - A[i].x));
				DP[i][j][0] = min(DP[i][j][0], DP[i+1][j][0] + (sum[i] + sum[N] - sum[j]) * (A[i+1].x - A[i].x));
				DP[i][j][1] = min(DP[i][j][1], DP[i][j-1][1] + (sum[i-1] + sum[N] - sum[j-1]) * (A[j].x - A[j-1].x));
				DP[i][j][1] = min(DP[i][j][1], DP[i][j-1][0] + (sum[i-1] + sum[N] - sum[j-1]) * (A[j].x - A[i].x));
			}

		printf("%d\n", V * min(DP[1][N][0], DP[1][N][1]));
	}

	return 0;
}
