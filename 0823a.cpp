#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int nA, nB, A[100010], B[100010];
	scanf("%d%d", &nA, &nB);
	int k, m;
	scanf("%d%d", &k, &m);
	for (int i = 0; i < nA; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < nB; i++)
		scanf("%d", &B[i]);
//	sort(A, A + k);
//	sort(B, B + m);
	if (A[k-1] < B[nB-m])
		puts("YES");
	else 
		puts("NO");

	return 0;
}
