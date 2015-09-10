#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, x, y, A[500050], T = 0;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &x, &y);
			A[x-1] = y;
		}

		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cnt += (A[cnt] < A[i]);
			*lower_bound(A, A + cnt, A[i]) = A[i];
		}
		printf("Case %d:\nMy king, at most %d road%s can be built.\n\n", ++T, cnt + 1, cnt > 0 ? "s" : "");
	}
	return 0;
}
