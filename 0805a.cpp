#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	long long A[100010];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%I64d", &A[i]);
	A[n + 1] = 1e15;
	A[0] = -1e15;
	for (int i = 1; i <= n; i++)
		printf("%I64d %I64d\n", min(A[i] - A[i - 1], A[i + 1] - A[i]), max(A[i] - A[1], A[n] - A[i]));


	return 0;
}
