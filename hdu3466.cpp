#include <cstdio>
#include <algorithm>
using namespace std;

struct Iterm {
	int P, Q, V;
	bool operator < (Iterm a) const {
		return Q - P < a.Q - a.P;
	}
} A[5050];

int main() {
	int N, M;
	while (scanf("%d%d", &N, &M) != EOF) {
		int DP[5050] = {0};
		for (int i = 0; i < N; ++i)
			scanf("%d%d%d", &A[i].P, &A[i].Q, &A[i].V);
		sort(A, A + N);

		for (int i = 0; i < N; ++i) {
			for (int j = M; j >= A[i].Q; j--)
				DP[j] = max(DP[j], DP[j-A[i].P] + A[i].V);
		}

		printf("%d\n", DP[M]);
	}
	return 0;
}
