#include <cstdio>
#include <algorithm>
using namespace std;
int DP[20000010];

int main() {
	int N, B, H[25], S = 0;
	scanf("%d%d", &N, &B);
	for (int i = 0; i < N; i++) {
		scanf("%d", &H[i]);
		S += H[i];
	}

	for (int i = 0; i < N; i++)
		for (int j = S; j >= H[i]; j--)
			DP[j] = max(DP[j], DP[j-H[i]] + H[i]);

	for (N = B; DP[N] < B; N++); 

	printf("%d\n", DP[N] - B);

	return 0;
}
