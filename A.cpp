#include <cstdio>
#include <algorithm>
using namespace std;

struct T {
	int x, a;
}; 

bool cmp(T p, T q) {
	return p.x < q.x;
}

bool cmp2(T p, T q) {
	return p.x > q.x;
}


int main() {
	T left[110], right[110];
	int N;
	while (scanf("%d", &N) != EOF) {
		int cnt1 = 0, cnt2 = 0, x, a;
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &x, &a);
			if (x < 0) {
				left[cnt1].x = x;
				left[cnt1].a = a;
				cnt1++;
			} else {
				right[cnt2].x = x;
				right[cnt2].a = a;
				cnt2++;
			}
			sort(left, left + cnt1, cmp2);
			sort(right, right + cnt2, cmp);
		}

		int ans = 0;
		for (int i = 0; i < cnt1 && i < cnt2; i++)
			ans += left[i].a + right[i].a;
		if (cnt1 > cnt2)
			ans += left[cnt2].a;
		else if (cnt2 > cnt1)
			ans += right[cnt1].a;
		printf("%d\n", ans);
	}
	return 0;
}
