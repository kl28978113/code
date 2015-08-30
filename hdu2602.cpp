#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, V, A[1010], B[1010], DP[1010] = {0};
		scanf("%d%d", &N, &V);
		for (int i = 0; i < N; i++)
			scanf("%d", &A[i]);
		for (int i = 0; i < N; i++)
			scanf("%d", &B[i]);

		for (int i = 0; i < N; i++)
			for (int j = V; j >= B[i]; j--)
				DP[j] = max(DP[j], DP[j-B[i]] + A[i]);

		printf("%d\n", DP[V]);
	}
	return 0;
}
