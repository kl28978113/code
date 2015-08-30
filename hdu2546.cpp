#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	while (scanf("%d", &n) && n) {
		int A[1010], DP[1010] = {0};
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		scanf("%d", &m);
		sort(A, A + n);

		for (int i = 0; i < n-1; i++)
			for (int j = m - 5; j >= A[i]; j--)
				DP[j] = max(DP[j], DP[j-A[i]] + A[i]);

		printf("%d\n", m < 5 ? m : m - DP[m-5] - A[n-1]);
	}
	return 0;
}
