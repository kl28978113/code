#include <cstdio>
#include <algorithm>
using namespace std;
int n, p[1000010], s[1000010], h[1000010];

int main() {
	int Z;
	scanf("%d", &Z);
	while (Z--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &p[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &s[i]);

		int level = s[0];
		for (int i = 0; i < n; i++) {
			if (level > s[i]) level = s[i];
			if (level < p[i]) level = p[i];
			h[i] = level;
		}

		level = s[n-1];
		int ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (level > s[i]) level = s[i];
			if (level < p[i]) level = p[i];
			ans += min(level, h[i]) - p[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
