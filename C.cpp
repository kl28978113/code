#include <cstdio>
#include <algorithm>
using namespace std;

int a, n, k = 0;
const int maxn = (1<<20);
int cost[maxn], vis[maxn], tmp[maxn], Count[maxn], rec[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);

		for (int i = 0; i <= 20; i++) {
			int num = a>>i;
			if (num == 0) continue;
			for (int j = 0; num < maxn-1; num *= 2, j++) {
				if (!vis[num]) {
					cost[num] = i + j;
					vis[num] = true;
					tmp[k++] = num;
				} else 
					cost[num] = min(i + j, cost[num]);
			}
		}

		for (int j = 0; j < k; j++) {
			vis[tmp[j]] = false;
			Count[tmp[j]] += cost[tmp[j]];
			rec[tmp[j]]++;
		}
		k = 0;
	}

	int ans = 0x3f3f3f3f;
	for (int i = 0; i < maxn; i++)
		if (rec[i] == n) ans = min(ans, Count[i]);

	printf("%d\n", ans);
	return 0;
}
