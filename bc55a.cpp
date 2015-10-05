#include <cstdio>
#include <algorithm>
using namespace std;

int n; 
double A[10100], B[10010];

bool judge(double h) {
	double sum = 0, sum2 = 0;
	for (int i = 0; i < n; i++) {
		sum += 1.0/3 * B[i] * B[i] * A[i];
		double tmp = (A[i] - h)/ A[i];
		if (A[i] > h) {
			sum2 += 1.0/3 *  B[i] * B[i] * tmp * tmp * (A[i] - h);
		}
	}
//	printf("sum2 = %lf, h = %lf)  ", sum2, h);

	return sum2 > sum / 2;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		double MAX = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lf", &A[i]);
			MAX = max(A[i], MAX);
		}
		for (int i = 0; i < n; i++)
			scanf("%lf", &B[i]);

		double MIN = 1;
		while (MIN < MAX - 1e-5) {
			// printf("%lf %lf  , ", MIN, MAX);
			double mid = (MIN + MAX) / 2;
			if (judge(mid))
				MIN = mid;
			else 
				MAX = mid;
		}
		printf("%d\n", int (MIN));
	}
	return 0;
}
