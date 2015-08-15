#include <cstdio>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;
	bool operator < (const Point& a) const {
		if (x != a.x)
			return x < a.x;
		return y < a.y;
	}
} A[500050], B[500050];

bool solve(int k1, int k2) {
	if (k1 != k2)
		return false;
	for (int i = 0; i < k1; i++)
		if (A[i].x != B[i].x || A[i].y != B[i].y)
			return false;
	return true;
}

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		int k1 = 0, k2 = 0;
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (x < y)
				A[k1].x = x, A[k1++].y = y;
			else 
				B[k2].x = y, B[k2++].y = x;
		}
		sort(A, A + k1);
		sort(B, B + k2);
		
		puts(solve(k1, k2) ? "YES" : "NO");
	}
	return 0;
}
