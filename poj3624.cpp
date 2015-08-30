#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	while (scanf("%d%d", &N, &M) != EOF) {
		int DP[13000] = {0};
		for (int i = 0; i < N; i++) {
			int W, D;
			scanf("%d%d", &W, &D);
			for (int j = M; j >= W; j--)
				DP[j] = max(DP[j], DP[j-W] + D);
		}
		printf("%d\n", DP[M]);
	}
	return 0;
} 
