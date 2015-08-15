#include <cstdio>
#include <algorithm>
using namespace std;

int N, W, H, M, y[110];

struct Point {
	int x, y;
	bool operator < (const Point& a) const {
		return x < a.x;
	}
} p[110];

void init() {
	scanf("%d%d%d", &N, &W, &H);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &p[i].x, &p[i].y);
		y[i] = p[i].y;
	}
	y[N] = 0; 
	y[N+1] = H;
	sort(y, y + N + 2);
	sort(p, p + N);
	M = unique(y, y + N + 2) - y;
}

void solve() {
	int ans = 0, ansx, ansy;
	for (int i = 0; i < M; i++)
		for (int j = i + 1; j < M; j++) {
			int h = y[j] - y[i], w, pre = 0;
			for (int k = 0; k < N; k++) {
				if (p[k].y <= y[i] || p[k].y >= y[j])
					continue;
				w = p[k].x - pre;
				if (ans < min(w, h)) {
					ans = min(w, h);
					ansx = pre;
					ansy = y[i];
				}
				pre = p[k].x;
			}

			if (ans < (min(W - pre, h))) {
				ans = min(W - pre, h);
				ansx = pre;
				ansy = y[i];
			}
		}
	printf("%d %d %d\n", ansx, ansy, ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		init();
		solve();
		if (T) puts("");
	}
	return 0;
}
