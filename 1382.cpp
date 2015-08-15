#include <cstdio>
#include <algorithm>
using namespace std;

struct Point {
	int x;
	int y;
	bool operator < (const Point& a) const {
		return  x < a.x;
	}
};

const int maxn = 100 + 10;
Point P[maxn];
int y[maxn], on[maxn], on2[maxn], left[maxn];

int solve(int N) {
	sort(P, P + N);
	sort(y, y + N);
	int m = unique(y, y + N) - y;
	if (m <= 2) return N;

	int ans = 0;
	for (int a = 0; a < m; a++)
		for (int b = a + 1; b < m; b++) {
			int ymin = y[a], ymax = y[b];

			int k = 0;
			for (int i = 0; i < N; i++) {
				if (i == 0 || P[i].x != P[i-1].x) {
					k++;
					on[k] = on2[k] = 0;
					left[k] = left[k-1] + on2[k-1] - on[k-1];
				}
				if (P[i].y > ymin && P[i].y < ymax) on[k]++;
				if (P[i].y >= ymin && P[i].y <= ymax) on2[k]++;
			}
			if (k <= 2) return N;

			int M = 0;
			for (int j = 1; j <= k; j++) {
				ans = max(ans, left[j] + on2[j] + M);
				M = max(M, on[j] - left[j]);
			}
		}
	return ans;
}

int main() {
	int N, kase = 0;
	while (scanf("%d", &N), N) {
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &P[i].x, &P[i].y);
			y[i] = P[i].y;
		}
		printf("Case %d: %d\n", ++kase, solve(N));
	}
	return 0;
}


