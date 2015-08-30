#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int N, sum = 0, A[45], DP[890][890] = {1};
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		sum += A[i];
	}

	for (int k = 0; k < N; k++)
		for (int i = sum/2; i >= 0; i--)
			for (int j = i; j >= 0; j--)
				if(DP[i][j]) 
					DP[i+A[k]][j] = DP[i][j+A[k]] = 1;

	int ans = -1;
	for (int i = 1; i <= sum/2; i++)
		for (int j = 1; j <= i; j++)
			if (DP[i][j]) 
				ans = max(ans, int(25 * sqrt(1.0 * sum * (sum-i-i) * (sum-j-j) * (2*(i+j)-sum))));

	printf("%d\n", ans);
	return 0;
}
