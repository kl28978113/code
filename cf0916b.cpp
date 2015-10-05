#include <cstdio>
#include <algorithm>
using namespace std;

struct Point {
	int x, y, v;
	bool operator < (Point a) const {
		return v > a.v;
	}
} A[1600100];

int main() {
	int n;
	scanf("%d", &n);
	int MAX = n * 2, tmp, cnt = 0;
	for (int i = 2; i <= MAX; i++)
		for (int j = 1; j < i; j++) {
			scanf("%d", &tmp);
			A[cnt].v = tmp;
			A[cnt].x = i;
			A[cnt++].y = j;
		}
	sort(A, A + cnt);
	int vis[10000] = {0}, ans[1000], cur = 0;
	for (int i = 0; cur < n; i++) {
		if (vis[A[i].x] || vis[A[i].y])
			continue;
			vis[A[i].x] = 1;
			vis[A[i].y] = 1;
			ans[A[i].x] = A[i].y; 
			ans[A[i].y] = A[i].x; 
			cur++;
	}
	for (int i = 1; i < MAX; i++)
		printf("%d ", ans[i]);
	printf("%d\n", ans[MAX]);
	
	return 0;
}
