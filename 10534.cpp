#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N; 
	while (scanf("%d", &N) != EOF) {
		int A[10010], B[10010], DP[10010], DP2[10010];
		for (int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
			B[N-i-1] = A[i];
		}
		for (int i = 0; i < N; i++) {
			DP[i] = 1;
			for (int j = 0; j < i; j++) if (A[i] > A[j])
				DP[i] = max(DP[i], DP[j] + 1);
		} 
		for (int i = 0; i < N; i++) {
			DP2[i] = 1;
			for (int j = 0; j < i; j++) if (B[i] > B[j])
				DP2[i] = max(DP2[i], DP2[j] + 1);
		}

		int ans = 1;
		for (int i = 0; i < N; i++) {
			if (DP[i] > 1 && DP2[N-i-1] > 1)
			ans = max(ans, DP[i] + DP2[N-i-1] - 1);
		}

		printf("%d\n", ans);
	}
	return 0;
}

