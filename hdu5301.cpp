#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, m, x, y;
	while (scanf("%d%d%d%d", &n, &m, &x, &y) != EOF) {
		if (n == m && x == y && n % 2 == 1 && n / 2 + 1 == x) {
			printf("%d\n", n / 2);
			continue; 
		}
		int tx = min(x, n - x + 1);
		    tx = max(tx, min((m + 1) / 2, n - tx));

		int ty = min(y, m - y + 1);
			ty = max(ty, min((n + 1) / 2, m - ty)); 
		int t = min(tx, ty);
		printf("%d\n", t);
	}
	return 0;
}
