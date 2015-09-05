#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int vis[100010], rec[1000000];

int main() {

	int m = sqrt(2 * 1e9 + 0.5);
	for (int i = 2; i <= m; i++) if (!vis[i])
		for (int  j = i * i; j <= 100000; j += i)
			vis[j] = 1;

	vis[1] = 1;

	int T;
	scanf("%d", &T);
	while (T--) {
		int n, cnt = 0, tmp;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			if (tmp == 1) continue;

			for (int j = 2; j <= 100000; j++) {
				if (vis[j] == 0)
					while (tmp % j == 0) {
						tmp /= j;
						rec[cnt++] = j;
					}
			}

			if (tmp != 1)
				rec[cnt++] = tmp;
		}

		sort(rec, rec + cnt);
		long long hehe = 1;
		if (cnt >= 2)
			printf("%lld\n", hehe * rec[0] * rec[1]);
		else
			puts("-1");
	}
	return 0;
}
