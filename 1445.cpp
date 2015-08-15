#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int w, d;
	while (scanf("%d%d", &w, &d) && w + d) {
		int h, F[25] = {0}, S[25] = {0};
		for (int i = 0; i < w; i++) {
			scanf("%d", &h);
			F[h]++;
		}
		for (int i = 0; i < d; i++) {
			scanf("%d", &h);
			S[h]++;
		}

		int ans = 0;
		for (int i = 1; i <= 20; i++)
			ans += max(F[i], S[i]) * i;
	
		printf("%d\n", ans);
	}
	return 0;
}
