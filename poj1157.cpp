#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int F, V;
	while (scanf("%d%d", &F, &V) != EOF) {
		int A, cur = 0, pre = 1, DP[2][110] = {-0x3f3f3f3f};
		for (int i = 1; i <= F; i++) {
			for (int j = 1; j <= V; j++) {
				scanf("%d", &A);
				if (j >= i && j <= V - F + i)
					DP[cur][j] = max(DP[cur][j-1], DP[pre][j-1] + A);
				else 
					DP[cur][j] = -0x3f3f3f3f;
			}
			swap(cur, pre);
		}
		printf("%d\n", DP[pre][V]);
	}
	return 0;
}
