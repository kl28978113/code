#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
	double pi = acos(-1.0);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, ans[450] = {0};
		double res = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int r, A, B;
			scanf("%d%d%d", &r, &A, &B);
			for (int i = A + 90; i < B + 90; i++)
				ans[i] = max(ans[i], r);
		}
		for (int i = 0; i < 360; i++)
			res += pi * (1.0 / 360) * ans[i] * ans[i];
		printf("%.3lf\n", res);
	}
	return 0;
}
