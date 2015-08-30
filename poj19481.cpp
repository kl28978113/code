#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int N, sum = 0, A[45], DP[810][810] = {1};
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		sum += A[i];
	}

	for (int k = 0; k < N; k++)
		for (int i = sum/2; i >= 0; i--)
			for (int j = sum/2; j >= 0; j--)
				if (i >= A[k] && DP[i-A[k]][j] || j >= A[k] && DP[i][j-A[k]])
					DP[i][j] = 1;

	double ans = -1;
	for (int i = 1; i <= sum/2; i++)
		for (int j = 1; j <= i; j++)
			if (DP[i][j] && sum > 2 * max(sum-i-j, max(i, j)))
				ans = max(ans, sqrt(sum * (sum-2*i) * (sum-2*j) * (2*(i+j)-sum)) / 4.0);

	printf("%d\n", ans < 0 ? -1 : int(ans * 100));
	return 0;
}
