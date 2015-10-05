#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std; 

int main() {
	char A[110], B[110];
	while (scanf("%s%s", A+1, B+1) != EOF) {
		int DP[110][110] = {0};
		int n = strlen(A+1), m = strlen(B+1);

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (A[i] == B[j])
					DP[i][j] = DP[i-1][j-1] + 1;
				else
					DP[i][j] = max(DP[i][j-1], DP[i-1][j]);
		printf("%d\n", DP[n][m]);
	}
	return 0;
}
