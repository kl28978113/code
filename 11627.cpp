#include <cstdio>
#include <algorithm>
using namespace std;

int W, v, N, S;
int x[100010], y[100010], s[1000010];

bool judge(int Vh) {
	double l = x[N-1], r = x[N-1] + W; 
	for (int i = N - 2; i >= 0; i--) {
		double t = 1.0 * (y[i+1] - y[i]) / Vh;
		l -= t * v;
		r += t * v;

		if (x[i] + W < l || x[i] > r)
			return false;
		if (l < x[i])
			l = x[i];
		if (r > x[i] + W)
			r = x[i] + W; 
	}
	return true;
}

void solve() {
	int L = 0, R = S - 1;
	while (L < R) {
		int mid = (L + R + 1) / 2;
		if (judge(s[mid]))
			L = mid;
		else 
			R = mid - 1;
	}
	if (judge(s[L]))
		printf("%d\n", s[L]);
	else 
		printf("IMPOSSIBLE\n");

}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &W, &v, &N);
		for (int i = 0; i < N; i++)
			scanf("%d%d", &x[i], &y[i]);
		scanf("%d", &S);
		for (int i = 0; i < S; i++)
			scanf("%d", &s[i]);
		sort(s, s + S);

		solve();
	}
	return 0;
}

