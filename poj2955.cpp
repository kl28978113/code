#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int main() {
	char str[110];
	while (scanf("%s", str) && str[0] != 'e') {
		int DP[110][110] = {0};
		int n = strlen(str); 
		for (int i = n-2; i >= 0; --i)
			for (int j = i+1; j < n; j++) {
				DP[i][j] = DP[i+1][j];
				for (int k = i+1; k <= j; k++)
					if ((str[i] == '(' && str[k] == ')') || (str[i] == '[' && str[k] == ']'))
						DP[i][j] = max(DP[i][j], DP[i+1][k-1] + 2 + DP[k+1][j]);
			}

		printf("%d\n", DP[0][n-1]);
	}
	return 0;
}
