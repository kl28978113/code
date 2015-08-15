#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M, R[20];
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++)
			scanf("%d", &R[i]);
		int MAX = 1 << N;
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < N; j++)
				if (i & (j << N))
					DP[i] = DP[]
	}
	return 0;
}
