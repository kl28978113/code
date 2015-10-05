#include <cstdio>

int main() {
	int T, kase = 1;
	scanf("%d", &T);
	while (T--) {
		int n, A, B, Len;
		scanf("%d%d%d%d", &n, &A, &B, &Len);
		int cur = 0, pre = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			int L, R;
			scanf("%d%d", &L, &R);
			cur += (L - pre) * B;
			cur -= (R - L) * A;
			if (cur < 0) {
				sum += -cur;
				cur = 0;
			}
			pre = R;
		}
		printf("Case #%d: %d\n", kase++, sum);
	}
	return 0;
}
