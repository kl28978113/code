#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int L, x, DP[100010], INF = 0x3f3f3f3f;
	while (scanf("%d", &L) != EOF) {
		fill(DP, DP + L, INF);
		for (int i = 0; i < L; i++) {
			scanf("%d", &x);
			*lower_bound(DP, DP + L, x) = x;
		}
		printf("%d\n", lower_bound(DP, DP + L, INF) - DP);
	}
	return 0;
}
