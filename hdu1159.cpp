#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	char A[1000], B[1000];
	while (scanf("%s%s", A+1, B+1) != EOF) {
		int DP[1000][1000] = {0};
		int n = strlen(A+1), m = strlen(B+1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (A[i] == B[j])
					DP[i][j] = DP[i-1][j-1] + 1;
				else
					DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
		printf("%d\n", DP[n][m]);
	}

	return 0;
}
