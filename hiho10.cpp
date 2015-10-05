#include <cstdio>
#include <cmath>
#include <bitset>
#include <algorithm>
using namespace std;

struct Point{
	int ID;
	int v;
	bool operator < (Point a) const {
		return v < a.v;
	}
} A[5][50010];

bitset<50010> b[6][230], ans[6]; 

int main() {
	int T;
	scanf("%d", &T);
	int n, m;
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 5; j++) {
				scanf("%d", &A[j][i].v);
				A[j][i].ID = i;
			}

		for (int i = 0; i < 5; i++)
			sort(A[i], A[i] + n);
			

		int block = (int)sqrt(1.0 * n);
		int num = n / block;

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < num; j++) {
				b[i][j].reset();
				if (j != 0)
					b[i][j] |= b[i][j-1];
				for (int k = 0; k < block; k++)
					b[i][j][A[i][j*block+k].ID] = 1;
			}
		}

		int q, C[10];
		int pre;
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			for (int j = 0; j < 5; j++)
				scanf("%d", &C[j]);

			if (i != 0)
				for (int j = 0; j < 5; j++)
					C[j] ^= pre;

			for (int j = 0; j < 5; j++) {
				int L = 0, R = n-1;
				if (A[j][0].v > C[j]) {
					ans[0].reset();
					break;
				}
				while (L <= R) {
					int mid = (L + R) / 2;
					if (A[j][mid].v <= C[j])
						L = mid + 1;
					else 
						R = mid - 1;
				}

				int cur = L / block - 1;
				if (cur >= 0)
					ans[j] = b[j][cur];
				else {
					cur = 0;
					ans[j].reset();
				}
				for (int k = cur*block; k < L; k++)
					ans[j][A[j][k].ID] = 1;
			}
			ans[0] = ans[0] & ans[1] & ans[2] & ans[3] & ans[4];
			pre = (int)ans[0].count();
			printf("%d\n", pre);
		}
	}
	return 0;
}
