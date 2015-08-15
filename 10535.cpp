#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double PI = acos(-1);
int x, y;

struct Wall {
	int x1, y1, x2, y2;
} W[510];

struct Segment {
	double p;
	int type;
	bool operator < (const Segment& a) const {
		return p != a.p ? p < a.p : type > a.type;
	}
} S[2010];

double cal(int x1, int y1) {
	if (y == y1 && x < x1) return 0;
	if (y < y1 && x == x1) return 90;
	if (y == y1 && x > x1) return 180;
	if (y > y1 && x == x1) return 270;
	double tmp = atan(1.0 * (y1 - y) / (x1 - x));
	if (tmp < 0) tmp += PI;
	if (y1 > y) return tmp / PI * 180;
	return tmp / PI * 180 + 180; 
}

int main() {
	int N;
	while (scanf("%d", &N) && N) {
		for (int i = 0; i < N; i++)
			scanf("%d%d%d%d", &W[i].x1, &W[i].y1, &W[i].x2, &W[i].y2);
		scanf("%d%d", &x, &y);

		int cnt = 0, ans = 0, cur = 0;
		for (int i = 0; i < N; i++) {
			double L = cal(W[i].x1, W[i].y1);
			double R = cal(W[i].x2, W[i].y2);
			if (L > R) swap(L, R);
			if (R - L >= 180) {
				double tmp = R;
				R = L;
				L = 0;
				S[cnt].p = L, S[cnt++].type = 1;
				S[cnt].p = R, S[cnt++].type = -1;
				L = tmp;
				R = 360;
			}
			S[cnt].p = L, S[cnt++].type = 1;
			S[cnt].p = R, S[cnt++].type = -1;
		}
		sort(S, S + cnt);
		for (int i = 0; i < cnt; i++) {
			cur += S[i].type;
			ans = max(ans, cur);
		}

		printf("%d\n", ans);
	}
	return 0;
}	
