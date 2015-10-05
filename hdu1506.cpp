#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	long long n, a[100010], l[100010], r[100010];
	while (scanf("%lld", &n) && n) {
		for (int i = 1; i <= n; ++i)
			scanf("%lld", &a[i]);
		a[0] = a[n+1] = -1;

		for (int i = 1; i <= n; ++i) {
			int pos = i - 1;
			while (a[pos] >= a[i])
				pos = l[pos];
			l[i] = pos;
		}

		for (int i = n; i >= 1; --i) {
			int pos = i + 1;
			while (a[pos] >= a[i])
				pos = r[pos];
			r[i] = pos;
		}

		long long ans = 0;
		for (int i = 1; i <= n; ++i)
			ans = max(ans, (r[i] - l[i] - 1) * a[i]);
		printf("%lld\n", ans);
	}
	return 0;
}
