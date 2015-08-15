#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

double pi = acos(-1);
int cnt;

struct Point {
	double l, r;
	bool operator < (Point a) const {
		return r < a.r;
	}
} A[500];

double cal(double x, double y) {
	return sqrt(x*x + y*y);
}

int solve() {
	sort(A, A + cnt);
	for (int i = 0; i < cnt; i++) {
		A[i + cnt].l = A[i].l + 2 * pi;
		A[i + cnt].r = A[i].r + 2 * pi;
	}

	int ans = cnt;
	for (int i = 0; i < cnt; i++) {
		double val = A[i].r;
		int tmp = 1;
		for (int j = i + 1; j < cnt + i; j++) if (A[j].l > val + 1e-9) {
			val = A[j].r;
			tmp++;
		}
		ans = min(ans, tmp);
	}

	return ans;
}

int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		int n;
		double d, x, y;
		scanf("%d%lf", &n, &d);
		cnt = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &x, &y);
			if (cal(x, y) <= d) continue;
			double angle = atan2(y, x);
			double range = asin(d / cal(x, y));
			A[cnt].l = angle - range;
			A[cnt++].r = angle + range; 
			if (A[cnt-1].r <= pi) continue;
			A[cnt-1].r -= 2 * pi; 
			A[cnt-1].l -= 2 * pi;
		}

		printf("%d\n", solve());
	}
	return 0;
}
