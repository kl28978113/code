#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, X, A[3010], B[3010];
	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &X);
			A[X] = i;
		}

		for (int i = 0; i < n; i++) 
			scanf("%d", &B[i]);

		int ans = 0;
		for (int i = 0; i < n; i++) {
			int MIN = A[B[i]], MAX = A[B[i]];
			for (int j = i + 1; j < n; j++) {
				MIN = min(MIN, A[B[j]]);
				MAX = max(MAX, A[B[j]]);
				if (j - i == MAX - MIN)
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
