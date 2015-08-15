#include <cstdio>
#include <algorithm>
using namespace std;

void update(int x, int a, int w, double &L, double &R) {
	if (a == 0) {
		if (x <= 0 || x >= w)
			R = L - 1;
	} else if (a > 0) {
		L = max(L, 1.0 * (0 - x) / a);
		R = min(R, 1.0 * (w - x) / a);
	} else {
		L = max(L, 1.0 * (w - x) / a); 
		R = min(R, 1.0 * (0 - x) / a);
	}
}

struct E {
	double p;
	int type; bool operator < (const E& a) const {
		return p < a.p || (p == a.p && type < a.type);
	}
} A[200005];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int w, h, n, cnt = 0;
		scanf("%d%d%d", &w, &h, &n);

		for (int i = 0; i < n; ++i) {
			int x, y, a, b;
			scanf("%d%d%d%d", &x, &y, &a, &b);

			double L = 0, R = 1e9;
			update(x, a, w, L, R);
			update(y, b, h, L, R);

			if (L < R) {
				A[cnt].p = L;
				A[cnt++].type = 1;
				A[cnt].p = R;
				A[cnt++].type = 0;
			}

		}

		sort(A, A + cnt);
		int MAX = 0, ans = 0;
		for (int i = 0; i < cnt; ++i)
			if (A[i].type == 1) {
				ans++;
				if (ans > MAX)
					MAX = ans;
			} else
				ans--;

		printf("%d\n", MAX);
	}
	return 0;
}


