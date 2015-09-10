#include <cstdio> 
#include <algorithm>
using namespace std;

struct Point {
	int x, T;
	bool operator < (Point a) const {
		return T < a.T;
	}
} A[100010];

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		int MAX = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &A[i].x, &A[i].T);
			MAX = max(MAX, A[i].T);
		}
		sort(A, A + n);

		int cnt = 0, cur = 1, pre = 0, DP[2][15] = {0};
		int pos[15] = {0};
		pos[6] = 1;

		for (int i = 1; i <= MAX; i++) {
			if (i <= 6)
				pos[6-i] = pos[6+i] = 1;

			for (int j = 1; j <= 11; j++)
				if (pos[j])
					DP[cur][j] = max(DP[pre][j], max(DP[pre][j+1], DP[pre][j-1]));

			while (cnt < n && A[cnt].T == i) {
				if (pos[A[cnt].x+1])
					DP[cur][A[cnt].x+1]++;
				cnt++;
			}
			swap(cur, pre);
		}

		int ans = 0;
		for (int i = 1; i <= 11; i++)
			if (pos[i])
				ans = max(ans, DP[pre][i]);

		printf("%d\n", ans);
	}
	return 0;
}
