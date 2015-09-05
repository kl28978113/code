#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T); 
	while (T--) {
		double P, p[110], DP[11000] = {1.0};
		int N, sum = 0, m[110];
		scanf("%lf%d", &P, &N);
		
		for (int i = 0; i < N; i++) {
			scanf("%d%lf", &m[i], &p[i]);
			sum += m[i];
			p[i] = 1.0 - p[i];
		}

		for (int i = 0; i < N; i++)
			for (int j = sum; j >= m[i]; j--)
				DP[j] = max(DP[j], DP[j-m[i]] * p[i]);

		while (1.0 - DP[sum] >= P) sum--;

		printf("%d\n", sum);
	}
	return 0;
}
