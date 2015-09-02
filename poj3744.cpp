#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct mm {
	double t[3][3];
};

mm Mul(mm a, mm b) {
	mm ans;
	ans.t[0][0] = ans.t[0][1] = ans.t[1][0] = ans.t[1][1] = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				ans.t[i][j] += a.t[i][k] * b.t[k][j]; return ans;
}

mm pow_M(mm a, int b) {
	mm ans;
	ans.t[0][0] = ans.t[1][1] = 1;
	ans.t[0][1] = ans.t[1][0] = 0;

	while (b > 0) {
		if (b % 2 == 1)
			ans = Mul(ans, a);
		b = b/2;
		a = Mul(a, a);
	}
	return ans;
}

int main() {
	int N, M[15];
	double p;
	while (cin >> N >> p) {
		for (int i = 0; i < N; i++)
			cin >> M[i];
		sort(M, M + N);
		mm m, t;

		m.t[0][0] = p;
		m.t[0][1] = 1;
		m.t[1][0] = 1 - p;
		m.t[1][1] = 0;

		mm tmp = pow_M(m, M[0] - 1);
		double res = 1.0 - tmp.t[0][0]; 
		for (int i = 1; i < N; i++) {
			tmp = pow_M(m, M[i] - M[i-1] - 1);
			res *= (1.0 - tmp.t[0][0]);
		}
		printf("%.7f\n", res);
	}
	return 0;
}
