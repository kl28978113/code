#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, A[10010];
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &A[i]);
		sort(A, A + n);
		printf("%d\n", A[n/2]);
	}
	return 0;
}


