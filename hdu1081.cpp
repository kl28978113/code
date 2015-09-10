#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int A[110][110] = {0}, tmp;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				scanf("%d", &tmp);
				A[i][j] += A[i-1][j] + tmp;
			}
		int ans = -127;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < i; j++)  {
				int sum = 0;
				for (int k = 1; k <= n; k++) { 
					if (sum >= 0)
						sum += A[i][k] - A[j][k];
					else
						sum = A[i][k] - A[j][k];
					ans = max(ans, sum);
				}
			}
		printf("%d\n", ans);
	}
	return 0;
}
