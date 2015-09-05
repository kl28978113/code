#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
int DP[3102010];

int main() {
	double Q;
	int N, m;
	while (scanf("%lf%d", &Q, &N) && N) {
		memset(DP, 0, sizeof(DP));
		for (int i = 0; i < N; ++i) {
			scanf("%d", &m);
			bool flag = true;
			double sum = 0, A = 0, B = 0, C = 0, p;
			for (int j = 0; j < m; ++j) {
				char str[30];
				scanf("%s", str);
				p = atof(str + 2);
				if (str[0] == 'A')
					A += p;
				if (str[0] == 'B')
					B += p;
				if (str[0] == 'C')
					C += p;
				sum += p;
				if ((str[0] != 'A' && str[0] != 'B' && str[0] != 'C') || A > 600 || B > 600 || C > 600 || sum > 1000)
					flag = false;
			}

			if (flag) for (int j = int(Q*100); j >= int(sum*100); j--)
				DP[j] = max(DP[j], DP[j-int(sum*100)] + int(sum*100));
		}
		printf("%.2lf\n", DP[int(Q*100)] * 0.01);
	}
	return 0;
}
