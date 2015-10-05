#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, p, DP[51500];
		scanf("%d%d%d", &n, &m, &p);
		memset(DP, 0x3f3f3f3f, sizeof(DP));
		DP[0] = 0;
		for (int i = 0; i < n; i++) {
			int t, u, v;
			int xxx, yyy;
			int sum = 0;
			scanf("%d%d%d", &t, &u, &v);
			for (int k = 1; sum < v; k *= 2) {
				if (sum + k <= v) {
					xxx = k * t;
					yyy = k * u;
					sum += k;
				} else {
					xxx = (v - sum) * t;
					yyy = (v - sum) * u;
					sum = v;
				}
				for (int j = p + 100; j >= xxx; j--)
					DP[j] = min(DP[j], DP[j-xxx] + yyy);
			}
		}
		int MIN = 0x3f3f3f3f;
		for (int i = p; i <= p + 100; i++) {
			if (DP[i] != 0x3f3f3f3f) {
				MIN = min(MIN, DP[i]);
			}
		}

		if (MIN == 0x3f3f3f3f) {
			puts("TAT");
			continue;
		}

		memset(DP, 0, sizeof(DP));
		for (int i = 0; i < m; i++) {
			int x, y, z;
			int xxx, yyy;
			int sum = 0;
			scanf("%d%d%d", &x, &y, &z);
			for (int k = 1; sum < z; k *= 2) {
				if (sum + k <= z) {
					xxx = k * x;
					yyy = k * y;
					sum += k;
				} else {
					xxx = (z - sum) * x;
					yyy = (z - sum) * y;
					sum = z;
				}
				for (int j = 50000; j >= yyy; j--)
					DP[j] = max(DP[j], DP[j-yyy] + xxx);
			}
		}

		int ans = 0x3f3f3f3f;  
		for (int i = 0; i <= 50000; i++)
			if (DP[i] >= MIN) {
				ans = i;
				break;
			}

		if (ans == 0x3f3f3f3f) {
			puts("TAT");
			continue;
		}
		printf("%d\n", ans);
	}
	return 0;
}
