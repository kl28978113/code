#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int M1, M2, A[510], B[510], DP[510][510] = {0}, pre[510][510] = {0};
	scanf("%d", &M1);
	for (int i = 1; i <= M1; ++i) 
		scanf("%d", &A[i]);

	scanf("%d", &M2);
	for (int i = 1; i <= M2; ++i) 
		scanf("%d", &B[i]);

	int ans = 0, pos = 0, rec[510], I, J;
	for (int i = 1; i <= M1; ++i)
		for (int j = 1; j <= M2; ++j) {
			if (A[i] == B[j]) {
				int MAX = 0;
				for (int k = 1; k < i; ++k)
					if (A[k] < A[i] && MAX < DP[k][j-1]) {
						MAX = DP[k][j-1];
						pre[i][j] = k;
					}
				DP[i][j] = MAX + 1;
			}
			else
				DP[i][j] =  DP[i][j-1];

			if (ans < DP[i][j]) {
				ans = DP[i][j];
				I = i;
				J = j;
			}
		}

	printf("%d\n", ans);
	rec[0] = A[I];
	for (int i = 1; i < ans; i++) {
		rec[i] = A[pre[I][J]];
		I = pre[I][J];
		while(A[I] != B[--J]);
	}

	for (int i = ans-1; i >= 0; --i)
		printf("%d ", rec[i]);
	puts("");
	return 0; 
} 
