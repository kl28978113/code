#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int n, vmax;

struct Point {
	int r, d, w;
	bool operator < (const Point & a) const {
		return d > a.d;
	}
} p[10010];

bool cmp (Point a, Point b) {
	return a.r < b.r;
}

bool check(int mid) {
	priority_queue<Point> Q;
	int k = 0;
	for (int i = 1; i <= 20000; i++) {
		while (p[k].r < i && k != n) Q.push(p[k++]);
		int leve = mid;

		while (!Q.empty() && leve != 0) {
			Point cur = Q.top();
			Q.pop();
			if (cur.d < i) return false;
			if (cur.w > leve) {
				cur.w -= leve;
				leve = 0;
				Q.push(cur);
			} else 
				leve -= cur.w;
		}
	}
	if (Q.empty() && k == n)
		return true;
	return false;
}

int solve() {
	int L = 0, R = vmax;
	while (L < R) {
		int mid = (L + R) / 2;
		if (check(mid))
			R = mid;
		else
			L = mid + 1;
	}
	return R;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &p[i].r, &p[i].d, &p[i].w);
			vmax += p[i].w;
		}
		sort(p, p + n, cmp);
		printf("%d\n", solve());
	}
	return 0;
}
