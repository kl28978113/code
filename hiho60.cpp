#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char A[2110], B[2110];
int DP[2110][2110][2], F[2110][2110];

int main() {
	scanf("%s%s", A, B);
	int len_A = strlen(A);
	int len_B = strlen(B);

	for (int i = 1; i <= len_A; i++)
		for (int j = 1; j <= len_B; j++)
			if (A[i-1] == B[j-1])
				F[i][j] = F[i-1][j-1] + 1;

	for (int i = 1; i <= len_A; i++)
		for (int j = 1; j <= len_B; j++) {
			DP[i][j][1] = max(DP[i-1][j][1], DP[i][j-1][1]);
			if (F[i][j] >= 3) {
				DP[i][j][0] = max(DP[i-1][j-1][0] + 1, DP[i-3][j-3][1] + 3);
				DP[i][j][1] = max(DP[i][j][1], DP[i][j][0]);
			}
		}

	printf("%d\n", DP[len_A][len_B][1]);
	return 0;
}
