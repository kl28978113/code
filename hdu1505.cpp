#include <cstdio>
#include <algorithm>
using namespace std;

int H[1010][1010], L[1010], R[1010];
char A[1010][1010], tmp[10];

int main() {
	int K, N, M;
	scanf("%d", &K);
	while (K--) {
		scanf("%d%d", &M, &N);
		for (int i = 1; i <= M; ++i)
			for (int j = 1; j <= N; ++j) {
				scanf("%s", tmp);
				A[i][j] = tmp[0];
			}

		int ans = 0;
		for (int i = 1; i <= M; ++i) {
			H[i][0] = H[i][N+1] = -1;
			for (int j = 1; j <= N; ++j)
				if (A[i][j] != 'R') H[i][j] = H[i-1][j] + 1;
				else H[i][j] = 0;

			for (int j = 1; j <= N; ++j) {
				int pos = j - 1;
				while (H[i][pos] >= H[i][j])
					pos = L[pos];
				L[j] = pos;
			}

			for (int j = N; j >= 1; --j) {
				int pos = j + 1;
				while (H[i][pos] >= H[i][j])
					pos = R[pos];
				R[j] = pos;
				ans = max(ans, (R[j] - L[j] - 1) * H[i][j]);
			}
		}
		printf("%d\n", ans * 3);
	}
	return 0;
}

