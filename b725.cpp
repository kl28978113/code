#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, p, q;
		scanf("%d%d%d%d", &n, &m, &p, &q);
		if (m * p <= q)
			printf("%d\n", n * p);
		else 
			printf("%d\n", (n / m) * q + min((n % m) * p, q));
	}
	return 0;
}
