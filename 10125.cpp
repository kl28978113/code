#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int n, A[1010];
	while (scanf("%d", &n) && n) {
		map<int, int> M;
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		sort(A, A + n);

		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				M[A[i]+A[j]] = i * 1000 + j;

		for (int i = n - 1; i >= 0; i--)
			for (int j = i - 1; j >= 0; j--) {
				int tmp = M[A[i]-A[j]];
				if (tmp && (tmp % 1000) != i && (tmp / 1000) != j) {
					printf("%d\n", A[i]);
					goto flag;
				}
			}
		puts("no solution");
flag:;
	}
	return 0;
}
