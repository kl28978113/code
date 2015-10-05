#include <cstdio>
#include <algorithm> 
using namespace std;

long long A[5001000];

int main() {
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		int n;
		long long a, b;

		scanf("%d%lld%lld", &n, &a, &b);
		for (int i = 0; i < n; i++)
			scanf("%lld", &A[i]);
		sort(A, A + n);

		int MID = 0;
		if (A[0] >= 0) {
			MID = 0;
		}
		else if (A[n-1] <= 0) {
			MID = n-1;
		}
		else {
			for (int i = 0; i < n-1; i++)
			if (A[i] * A[i+1] <= 0) {
				MID = i;
				break;
			}
		}


		long long MAX = -0x3f3f3f3f;

		MAX = max(MAX, a * A[0] * A[0] + b * A[n-1]);
		MAX = max(MAX, a * A[0] * A[0] + b * A[1]);
		MAX = max(MAX, a * A[1] * A[1] + b * A[0]);


		MAX = max(MAX, a * A[n-1] * A[n-1] + b * A[0]);
		MAX = max(MAX, a * A[n-1] * A[n-1] + b * A[n-2]);
		MAX = max(MAX, a * A[n-2] * A[n-2] + b * A[n-1]);


		if (MID > 0 && MID < n - 1) {
			MAX = max(MAX, a * A[MID] * A[MID] + b * A[n-1]);
			MAX = max(MAX, a * A[MID-1] * A[MID-1] + b * A[n-1]);
			MAX = max(MAX, a * A[MID] * A[MID] + b * A[0]);
			MAX = max(MAX, a * A[MID+1] * A[MID+1] + b * A[0]);
		}

		if (MID < n - 2) {
			MAX = max(MAX, a * A[MID+1] * A[MID+1] + b * A[n-1]);
		}

		if (MID > 1) {
			MAX = max(MAX, a * A[MID-1] * A[MID-1] + b * A[0]);
		}


		printf("Case #%d: %lld\n", ++kase, MAX);
	}
	return 0;
}
