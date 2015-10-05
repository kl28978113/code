#include <cstdio>
#include <algorithm>
using namespace std;


int M, N, ans;
double X[110], Y[110], A[110][110];
bool flag;

bool judge(int R, int cur) {
	double ran = 1.0 * R * R;
	int pos = 0;
	for (int i = 0; i < M; i++) {
		if (A[cur][i] < ran)
			pos++;
	}

	if (pos == N && (N == M || A[cur][pos] != ran)) {
		//printf("%d R = %d\n", pos, R);
		flag = true;
		ans = min(ans, R);
	//	return true;
	}
	if (pos >= N)
		return true;

	return false;

	//	for (int i = 0; i < M; i++) {
	//int pos = lower_bound(A[i], A[i] + M, ran) - A[i];
	//		 int pos = 0;
	//		 for (int j = 0; j < M; j++)
	//			 if (A[i][j] <= ran)
	//				 pos++;

	//		printf("ran = %lf, pos = %d \n", ran, pos);
	// if (pos >= N) {
	//	printf("YES i = %d, ran = %lf, pos = %d \n", i, ran, pos);
	// if (pos == N && A[i][pos-1] != ran) {
	//	printf("YES ran = %lf, pos = %d \n", ran, pos);
	// flag = true;
	// ans = R;
	// }
	// if (A[i][pos] != ran)
	// ok = true;
	// }
	// }
	// if (ok) return true;
	// else return false;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &M, &N);
		for (int i = 0; i < M; i++)
			scanf("%lf%lf", &X[i], &Y[i]);
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++)
				A[i][j] = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
			sort(A[i], A[i] + M);
		}
		ans = 0x3f3f3f3f;

		//for (int i = 0; i < M; i++)
		//	for (int j = 0; j < M; j++)
		//printf("A[%d][%d] = %lf  \n", i, j, A[i][j]);
		flag = false;
		for (int i = 0; i < M; i++) {
			int L = 1, R = min(3000, ans);
			while (L < R) {
				int MID = (L + R) / 2;
				//	printf(" MID = %d, \n", MID);
				if (judge(MID, i)) {
					R = MID;
				} else 
					L = MID + 1;
			}
		}

		if (flag)
			printf("%d\n", ans);
		else 
			printf("-1\n");
		//printf("%d\n", int (1998 * 1.414));
	}
	return 0;
}
