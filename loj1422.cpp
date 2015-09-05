#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T, cnt = 0;
	scanf("%d", &T);
	while (T--) {
		int N, A[110], DP[110][110];
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &A[i]);
		for (int i = 0; i < N; ++i) {
			DP[i+1][i] = 0;
			DP[i][i] = 1;
		}
		
		for (int i = 1; i < N; ++i) 
			for (int j = i-1; j >= 0; --j) {
				DP[j][i] = DP[j][i-1] + 1;
				for (int k = i-1; k >= j; k--)
					if (A[k] == A[i])
						DP[j][i] = min(DP[j][i], DP[j][k] + DP[k+1][i-1]);
			}

		printf("Case %d: %d\n", ++cnt, DP[0][N-1]);
	}
	return 0;
}
