#include <cstdio>
#include <algorithm>
using namespace std;

struct Block {
	int x, y, z;
	bool operator < (Block a) const {
		return x > a.x;
	}
} A[100];

int main() {
	int n, x, y, z, DP[100], T = 0;
	while(scanf("%d", &n) && n) {
		for (int i = 0; i < 3 * n; i += 3) {
			scanf("%d%d%d", &x, &y, &z);
			if (x < y) swap(x, y);
			if (x < z) swap(x, z);
			if (y < z) swap(y, z);
			A[i].x = x;
			A[i].y = y;
			A[i].z = z;
			A[i+1].x = x;
			A[i+1].y = z;
			A[i+1].z = y;
			A[i+2].x = y;
			A[i+2].y = z;
			A[i+2].z = x;
		}
		n *= 3;
		sort(A, A + n);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			DP[i] = A[i].z;
			for (int j = 0; j < i; j++)
				if (A[i].x < A[j].x && A[i].y < A[j].y && DP[i] < DP[j] + A[i].z)
					DP[i] = DP[j] + A[i].z;
			ans = max(ans, DP[i]);
		}
		printf("Case %d: maximum height = %d\n", ++T, ans);
	}
	return 0;
}





