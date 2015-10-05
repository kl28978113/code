#include <cstdio>
#include <cstring>

int main() {
	int n, kase = 0;
	char A[210], B[210], C[410];
	scanf("%d", &n);
	while (n--) {
		int DP[210][210] = {0};
		scanf("%s%s%s", A + 1, B + 1, C + 1);
		int p1, p2, flag, a, b; 
		a = strlen(A + 1);
		b = strlen(B + 1);
		for (int i = 1; i <= a; i++)
			if (A[i] == C[i]) DP[i][0] = 1;
			else break;

		for (int i = 1; i <= b; i++)
			if (B[i] == C[i]) DP[0][i] = 1;
			else break;

		for (int i = 1; i <= a; i++)
			for (int j = 1; j <= b; j++)
				if (DP[i-1][j] && A[i] == C[i+j])
					DP[i][j] = 1;
				else if(DP[i][j-1] && B[j] == C[i+j])
					DP[i][j] = 1;

		printf("Data set %d: %s\n", ++kase, DP[a][b] ? "yes" : "no");
	}
	return 0;
}

