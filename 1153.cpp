#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Order {
	int q;
	int d;
	bool operator < (const Order& a) const {
		return d < a.d;
	}
} A[800010];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &A[i].q, &A[i].d);
		sort(A, A + n);

		int cur = 0;
		priority_queue<int> que;
		for (int i = 0; i < n; i++) {
			cur += A[i].q;
			que.push(A[i].q);
			if (cur > A[i].d) {
				cur -= que.top();
				que.pop();
			}
		}

		printf("%ld\n", que.size());
		if (T) puts("");
	}
	return 0;
}
