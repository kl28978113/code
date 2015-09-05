#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	char str1[110], str2[110];
	while (scanf("%s%s", str1, str2) != EOF) {
		int DP[110][110] = {0};
		int n = strlen(str1);
		for (int i = 0; i < n; ++i)
			for (int j = i; j < n; ++j)
				DP[i][j] = j - i + 1;

		for (int i = n-2; i >= 0; --i)
			for (int j = i+1; j < n; ++j) {
				DP[i][j] = DP[i+1][j] + 1;
				for (int k = i+1; k <= j; ++k)
					if (str2[i] == str2[k])
						DP[i][j] = min(DP[i][j], DP[i+1][k-1] + DP[k][j]);
			}

		int ans[110];
		for (int i = 0; i < n; ++i) {
			ans[i] = DP[0][i];
			if (str1[i] == str2[i])
				ans[i] = i ? ans[i-1] : 0;

			for (int j = 0; j < i; ++j)
				ans[i] = min(ans[i], ans[j] + DP[j+1][i]);
		}

		printf("%d\n", ans[n-1]);
	}
	return 0;
}
