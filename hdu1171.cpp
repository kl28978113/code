#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int N, V[55], M[55];
	while (scanf("%d", &N) && N > 0) {
		int sum = 0;
		int DP[255555] = {0};
		for (int i = 0; i < N; ++i) {
			scanf("%d%d", &V[i], &M[i]);
			sum += V[i] * M[i];
		}

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M[i]; ++j)
				for (int k = sum / 2; k >= V[i]; k--)
					DP[k] = max(DP[k], DP[k-V[i]] + V[i]);

		printf("%d %d\n", sum - DP[sum/2], DP[sum/2]);
	}
	return 0;
}
