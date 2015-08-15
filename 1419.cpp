#include <cstdio>

int main() {
	char s[110][110];
	int n, m;
	while (scanf("%d%d", &n, &m) && n + m) {
		int ans[40] = {0};
		for (int i = 0; i < n; i++)
			scanf("%s", s[i]);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (s[i][j] != '.') {
					int left = 0, right = 0, up = 0, down = 0, flag = 1;
					char C = s[i][j];
					for (int k = j; k < m && s[i][k] == C; k++)
						up++;
					for (int k = i; k < n && s[k][j] == C; k++)
						left++;
					for (int k = i; k < n && s[k][j+up-1] == C; k++)
						right++;
					for (int k = j; k < m && s[i+left-1][k] == C; k++)
						down++;

					for (int p = i + 1; p < i + left - 1; p++)
						for (int q = j + 1; q < j + up - 1; q++)
							if (s[p][q] != '.')
								flag = 0;

					if (left == right && up == down && left > 2 && up > 2 && flag)
						ans[C-'A'] = 1;
				}

		for (int i = 0; i < 26; i++)
			if (ans[i])
				printf("%c", i + 'A');
		printf("\n");

	}
	return 0;
}
