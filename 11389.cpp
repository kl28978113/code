#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, d, r;
	while (scanf("%d%d%d", &n, &d, &r) && n + d + r) {
		int M[110], E[110];
		for (int i = 0; i < n; i++)
			scanf("%d", &M[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &E[i]);
		sort(M, M + n);
		sort(E, E + n);
		
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (M[i] + E[n-i-1] > d)
				ans += (M[i] + E[n-i-1] - d) * r;

		printf("%d\n", ans);
	}
	return 0;
}
