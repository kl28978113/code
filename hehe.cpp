#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long ll;
double dp[205];
double dp2[205];
int main() {
	int n, k, l, r;
	while (scanf("%d %d %d %d", &n, &k, &l, &r) == 4) {
		if (!n && !k && !l && !r) break;
		memset(dp, 0, sizeof(dp));

		double  ans = 0;
		int temp;
		dp[1] = 1;
		for (int i = 0; i < k; i++) {
			//memset(dp, 0, sizeof(dp));
			scanf("%d", &temp);	
			memset(dp2, 0, sizeof(double) * (n +2));

			for (int j = 1; j <= n; j++) {
				if (dp[j]) {
					int pa = j - temp;
					int pb = j + temp;
					if (pa < 1) pa = n + pa % n;
					if (pb > n) pb = pb % n;
					dp2[pa] += 0.5*dp[j];
					dp2[pb] += 0.5*dp[j];
				}
//				printf("%lf ", dp[j]);
			}
//			puts("");

			for (int j = 1; j <= n; j++) {
				dp[j] = dp2[j];
			}
		}

		for (int i = l; i <= r; i++) {
			ans += dp[i];
		}

		printf("%.4lf\n", ans);
	}
	return 0;
}


