#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int k;
		char S[1010];
		scanf("%d%s", &k, S);
		int len = strlen(S), A[1010] = {0}, DP[1010][26], M[1010][26] = {0};

		for (int i = 0; i < len; i++) {
			int x = S[i] - 'a';
			if (!M[i/k][x]) A[i/k]++;
			M[i/k][x]++;
		}

		memset(DP, 0x3f3f3f3f, sizeof(DP));
		for (int j = 0; j < 26; j++) DP[0][j] = A[0];

		for (int i = 1; i < len / k;  i++)
			for (int j = 0; j < 26; j++) if (M[i][j])
				for (int t = 0; t < 26; t++) if (M[i-1][t])
					DP[i][j] = min(DP[i][j], DP[i-1][t] + A[i] - (M[i][t] && (j != t || A[i] == 1)));

		int ans = len;
		for (int j = 0; j < 26; j++)
			ans = min(ans, DP[len/k - 1][j]);

		printf("%d\n", ans);
	}
	return 0;
}
