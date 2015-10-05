#include <cstdio>
#include <algorithm>
using namespace std;

int H[1010][1010], L[1010], R[1010];
char A[1010][1010];


int main() {
	int m, n;
	while (scanf("%d%d", &m ,&n) != EOF) {
		for (int i = 1; i <= m; ++i)
			scanf("%s", A[i]+1);


		int ans = 0;
		for (int i = 1; i <= m; ++i) {
			H[i][0] = H[i][m+1] = -1;
			for (int j = 1; j <= n; ++j) {
				if (A[i][j] != 'b' && A[i][j] != 'c' && A[i][j] != 'x')
					H[i][j] = H[i-1][j] + 1;
				else
					H[i][j] = 0;
			}

			for (int j = 1; j <= n; ++j) {
				int pos = j - 1;
				while (H[i][pos] >= H[i][j])
					pos = L[pos];
				L[j] = pos;
			}

			for (int j = n; j >= 1; --j) {
				int pos = j + 1;
				while (H[i][pos] >= H[i][j])
					pos = R[pos];
				R[j] = pos;
				ans = max(ans, (R[j] - L[j] - 1) * H[i][j]);
			}
		}

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (A[i][j] != 'a' && A[i][j] != 'c' && A[i][j] != 'y')
					H[i][j] = H[i-1][j] + 1;
				else
					H[i][j] = 0;
			}

			for (int j = 1; j <= n; ++j) {
				int pos = j - 1;
				while (H[i][pos] >= H[i][j])
					pos = L[pos];
				L[j] = pos;
			}

			for (int j = n; j >= 1; --j) {
				int pos = j + 1;
				while (H[i][pos] >= H[i][j])
					pos = R[pos];
				R[j] = pos;
				ans = max(ans, (R[j] - L[j] - 1) * H[i][j]);
			}
		}

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (A[i][j] != 'a' && A[i][j] != 'b' && A[i][j] != 'w')
					H[i][j] = H[i-1][j] + 1;
				else
					H[i][j] = 0;
			}

			for (int j = 1; j <= n; ++j) {
				int pos = j - 1;
				while (H[i][pos] >= H[i][j])
					pos = L[pos];
				L[j] = pos;
			}

			for (int j = n; j >= 1; --j) {
				int pos = j + 1;
				while (H[i][pos] >= H[i][j])
					pos = R[pos];
				R[j] = pos;
				ans = max(ans, (R[j] - L[j] - 1) * H[i][j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
