#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[110], DP[110][110];

int DPS(int L, int R) {
	if (DP[L][R] != 0x3f3f3f3f)
		return DP[L][R];

	if (R - L < 2)
		return 0;

	for (int i = L + 1; i < R; i++)
		DP[L][R] = min(DP[L][R], DPS(L, i) + A[L] * A[i] * A[R] + DPS(i, R));

	return DP[L][R];
}

int main() {
	int N;
	while (scanf("%d", &N) != EOF) {
		memset(DP, 0x3f3f3f3f, sizeof(DP));
		for (int i = 0; i < N; ++i)
			scanf("%d", &A[i]);

		printf("%d\n", DPS(0, N-1));
	}
	return 9;
}
