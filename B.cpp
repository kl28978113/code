#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct T {
	int left, right, dis, cnt;
} A[1000100];

bool cmp(T a, T b) {
	if (a.cnt != b.cnt)
		return  a.cnt > b.cnt;
	return a.dis < b.dis;
}

int main() {
	int N;
	while (scanf("%d", &N) != EOF) {
		int tmp, MIN;
		memset(A, 0, sizeof(A));
		for (int i = 1; i <= N; i++) {
			scanf("%d", &tmp);
			if (A[tmp].left == 0)
				A[tmp].left = i;
			A[tmp].cnt++;
			A[tmp].dis = i - A[tmp].left + 1;
			A[tmp].right = i;
		}
		sort(A, A + 1000010, cmp);
		printf("%d %d\n", A[0].left, A[0].right);
	}
	return 0;
}

