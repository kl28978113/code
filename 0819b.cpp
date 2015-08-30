#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int A[5], B[5], flag = 0;
		scanf("%d%d%d%d%d%d", &A[0], &B[0], &A[1], &A[2], &B[1], &B[2]);

	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= 2; j++)
			if (A[0] >= A[i] + B[j] && B[0] >= max(A[3-i], B[3-j]) || B[0] >= A[i] + B[j] && A[0] >= max(A[3-i], B[3-j]))
				flag = 1;

	flag ? puts("YES") : puts("NO");
	return 0;
}
