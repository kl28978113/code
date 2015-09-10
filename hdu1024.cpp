#include <cstdio>
#include <algorithm>
using namespace std;

int DP[1000010], MAX[1000010];

int main() {
	int m, n, tmp;
	while (scanf("%d%d%d", &m, &n, &tmp) != EOF) {
		MAX[1] = DP[1] = tmp;
		for (int i = 2; i <= n; ++i) { 
			scanf("%d", &tmp);
			DP[i] = MAX[i] = -0x3f3f3f3f;
			for (int j = min(i, m); j >= 1; --j) {
				DP[j] = max(DP[j] + tmp, MAX[j-1] + tmp);
				MAX[j] = max(MAX[j], DP[j]);
			}
		}
		printf("%d\n", MAX[m]);
	}
	return 0;
}
