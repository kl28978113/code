#include <cstdio> 
#include <cstring>
#include <algorithm>
using namespace std;

int Point[100010][15];

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		int x, T, MAX = 0;
		memset(Point, 0, sizeof(Point));
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &x, &T);
			Point[T][x+1]++;
			MAX = max(MAX, T);
		}

		int pos[15] = {0};
		pos[6] = 1;
		for (int i = 1; i <= MAX; i++) {
			if (i <= 6)
				pos[6+i] = pos[6-i] = 1;
			for (int j = 1; j <= 11; j++)
				if (pos[j]) {
					Point[i][j] += max(Point[i-1][j], max(Point[i-1][j+1], Point[i-1][j-1]));
				}
		}

		int ans = 0;
		for (int i = 1; i <= 11; i++)
			if (pos[i])
			ans = max(ans, Point[MAX][i]);

		printf("%d\n", ans);
	}
	return 0;
}
