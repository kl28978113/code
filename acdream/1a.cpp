#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int n, A[1010], m;
	while (scanf("%d", &n) != EOF) {
		int sum = 0, MAX = 0, MAXN = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
			sum += A[i];
			if (A[i] > MAX) {
				MAX = A[i];
				MAXN = i;
			}

		}
		scanf("%d", &m);

		if (m < 5) {
			printf("%d\n", m);
			continue;
		}

		if (sum <= m) {
			printf("%d\n", m - sum);
			continue;
		}

		int DP[10010] = {0}, ans = 0;
		for (int i = 0; i < n; i++) {
			if (i == MAXN)
				continue;
			for (int s = m - 5; s >= A[i]; s--)
				DP[s] = max(DP[s], DP[s-A[i]] + A[i]);
		}
		printf("%d\n", m - (DP[m-5] + MAX));
	}
	return 0;
}

