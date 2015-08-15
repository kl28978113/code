#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

const double PI = acos(-1.0);
char vis[2000000];
double tmp[5010];

struct Point {
	int x, y, r;
	double c;

	void get() {
		scanf("%d%d", &x, &y);
		r = x * x + y * y;
		c = atan2(y, x);
	} 

	bool operator < (const Point& a) const {
		return c < a.c;
	} 
} p[5010];

int main() {
	int T = 0, N, K;
	while (scanf("%d%d", &N, &K) && N + K) {
		for (int i = 0; i < N; i++)
			p[i].get();

		printf("Case #%d: ", ++T);
		if (K == 0) {
			puts("0.00");
			continue;
		}

		sort(p, p + N);
		memset(vis, 0, sizeof(vis));
		double ans = 0x3f3f3f3f;

		for (int i = 0; i < N; i++) {
			int R = p[i].r;
			if (vis[R]) continue;
			vis[R] = 1;

			int cnt = 0;
			for (int j = 0; j < N; j++)
				if (p[j].r <= R) 
					tmp[cnt++] = p[j].c;
			if (cnt < K) continue;

			for (int j = 0; j < cnt; j++) {
				int t = j + K - 1;
				if (t < cnt)
					ans = min(ans, 0.5 * R * (tmp[t] - tmp[j]));
				else
					ans = min(ans, 0.5 * R * (tmp[t-cnt] + 2 * PI - tmp[j]));
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
