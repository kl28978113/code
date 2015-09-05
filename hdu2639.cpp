#include <cstdio>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, V, K;
		scanf("%d%d%d", &N, &V, &K);
		int v[110], m[110], DP[1010][35] = {0};
		for (int i = 0; i < N; i++) 
			scanf("%d", &v[i]);
		for (int i = 0; i < N; i++) 
			scanf("%d", &m[i]);

		int A[35] = {0}, B[35] = {0};
		for (int i = 0; i < N; i++)
			for (int j = V; j >= m[i]; j--) {
				for (int r = 1; r <= K; r++) {
					A[r] = DP[j-m[i]][r] + v[i];
					B[r] = DP[j][r];
				}
				int a, b, c;
				a = b = c = 1;

				while (c <= K && (a <= K || b <= K)) {
					DP[j][c] = A[a] > B[b] ? A[a++] : B[b++];
					c += (DP[j][c] != DP[j][c-1]);
				}
			}
		printf("%d\n", DP[V][K]);
	}
	return 0;
}


