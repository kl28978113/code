#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int A[1000010] = {0}, cur = 0, cnt = 0, tmp = 0, x;
		char c[10];
		for (int i = 0; i < n; i++) {
			scanf("%s%d", c, &x);
			if (A[x] == 0) {
				if (c[0] == '-')
					tmp++;
				if (c[0] == '+') {
					cur++;
					A[x] = 1;
				}
			}
			else {
				A[x]--;
				cur--;
			}
			tmp = max(tmp, cur);
		}
		printf("%d\n", tmp);
	}
	return 0;
}
