#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int t;
	char s[1010];
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s + 1);
		int cnt = 0, sum = 0, ans= 0, a[1010] = {0}, b[1010] = {0};
		int len = strlen(s+1);
		for (int i = 1; i <= len; i++) {
			a[i] = a[i-1];
			if (s[i] == '(')
				a[i] += 1;
		}
		for (int i = len; i >= 1; i--) {
			b[i] = b[i+1];
			if (s[i] == '(')
				b[i] += 1;
		}
		ans = min(a[len], len - a[len]);

		for (int i = 1; i <= len; i++) {
			ans = min(ans, a[i] + ((len - i) - b[i+1]));
		}
		printf("%d\n", ans);
	}
	return 0;
}
