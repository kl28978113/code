#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T, A[1010];
	scanf("%d", &T);
	while (T--) {
		int N, ans = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &A[i]);
		if (N % 2) A[N++] = 0;
		sort(A, A + N);

		for (int i = 1; i < N; i += 2)
			ans ^= A[i] - A[i-1] - 1;

		if (ans) puts("Georgia will win");
		else puts("Bob will win");
	}
	return 0;
}
